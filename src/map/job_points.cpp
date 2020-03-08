/*
===========================================================================

  Copyright (c) 2010-2015 Darkstar Dev Teams

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see http://www.gnu.org/licenses/

  This file is part of DarkStar-server source code.

===========================================================================
*/

#include <string.h>

#include "map.h"
#include "job_points.h"
#include "entities/charentity.h"
#include "utils/charutils.h"

#define GetJobPointCategory(jp) ((jp >> 5) - 1)
#define GetJobPointIndex(jp) (jp & 0x1F)
#define MAX_JOB_POINTS 500
#define MAX_CAPACTIY_POINTS 30000

CJobPoints::CJobPoints(CCharEntity* PChar)
{
	DSP_DEBUG_BREAK_IF(sizeof(jobpoints) != sizeof(jobpointutils::GJobPointsTemplate));

    memcpy(jobpoints, jobpointutils::GJobPointsTemplate, sizeof(jobpoints));

    jp_PChar = PChar;
    LoadJobPoints(PChar->id);

    jp_CapacityPoints = 0;
    jp_JobPoints = 0;
}

void CJobPoints::LoadJobPoints(uint32 charid)
{
    uint8 catNumber = 0;

    for(uint16 i = 0; i < JOBPOINTS_COUNT; i++)
    {
       if(i == jobpointutils::groupOffset[catNumber])
       {
           Categories[catNumber] = &jobpoints[i];
           catNumber++;
       }
    }

    if(Sql_Query(SqlHandle, "SELECT jobpointid, upgrades FROM char_jobpoints WHERE charid = %u", charid) != SQL_ERROR)
    {
        for(uint16 i = 0; i < Sql_NumRows(SqlHandle); i++)
        {
           if(Sql_NextRow(SqlHandle) == SQL_SUCCESS)
           {
               uint32 jobPointID = Sql_GetUIntData(SqlHandle, 0);
               uint32 upgrades = Sql_GetUIntData(SqlHandle, 1);

               for(uint16 j = 0; j < JOBPOINTS_COUNT; j++)
               {
                   if(jobpoints[i].id == jobPointID)
                   {
                       jobpoints[i].value = upgrades;
                       jobpoints[i].next = (upgrades + 1) % 21;

                       // set up packet union
                       jobpoints[i].pid = jobpoints[i].id;
                       jobpoints[i].pnext = jobpoints[i].next;
                       jobpoints[i].pvalue = jobpoints[i].value << 2;
                   }
               }
           }
        }
    }
}

void CJobPoints::SaveJobPoints(uint32 charid)
{
    for (uint16 i = 0; i < JOBPOINTS_COUNT; ++i)
        if (jobpoints[i].value > 0)
            Sql_Query(SqlHandle, "INSERT INTO char_jobpoints (charid, jobpointid, value) VALUES(%u, %u, %u) ON DUPLICATE KEY UPDATE upgrades = %u", charid, jobpoints[i].id, jobpoints[i].value, jobpoints[i].value);
        else
            Sql_Query(SqlHandle, "DELETE FROM char_jobpoints WHERE charid = %u AND jobpointid = %u", charid, jobpoints[i].id);
}

uint16 CJobPoints::GetCapacityPoints()
{
    return jp_CapacityPoints;
}

uint8 CJobPoints::GetJobPoints()
{
    return jp_JobPoints;
}

void CJobPoints::SetCapacityPoints(uint16 points)
{
    jp_CapacityPoints = std::min<uint16>(points, MAX_CAPACTIY_POINTS - 1);
}

void CJobPoints::SetJobPoints(uint16 points)
{
    jp_JobPoints = std::min<uint8>(points, MAX_JOB_POINTS);
}

bool CJobPoints::IsJobPointExist(JOBPOINT_TYPE jobpoint)
{
    if((int16)jobpoint < JPCATEGORY_START) return false;
    if(GetJobPointCategory(jobpoint) > JPCATEGORY_COUNT) return false;
    if(GetJobPointIndex(jobpoint) > JOBPOINTS_PER_CATEGORY) return false;

    return true;
}

const JobPoint_t* CJobPoints::GetJobPointByIndex(uint16 index)
{
    DSP_DEBUG_BREAK_IF(index >= JOBPOINTS_COUNT);

	return  &jobpoints[index];
}

JobPoint_t* CJobPoints::GetJobPointPointer(JOBPOINT_TYPE jobpoint)
{
    if (IsJobPointExist(jobpoint))
    {
        return &Categories[GetJobPointCategory(jobpoint)][GetJobPointIndex(jobpoint)];
    }
    return nullptr;
}

void CJobPoints::RaiseJobPoint(JOBPOINT_TYPE jobpoint)
{
    JobPoint_t* PJobPoint = GetJobPointPointer(jobpoint);
}

namespace jobpointutils
{
	JobPoint_t  GJobPointsTemplate[JOBPOINTS_COUNT] = {0};	// global list of jobpoints
	int16       groupOffset[JPCATEGORY_COUNT] = {0};		// the first jp of each job

    void LoadJobPointsList()
    {
        int32 ret = Sql_Query(SqlHandle, "SELECT m.job_pointid, m.catid, m.jobs, ORDER BY m.job_pointid ASC LIMIT %u", JOBPOINTS_COUNT);

        if(ret != SQL_ERROR && Sql_NumRows(SqlHandle) != JOBPOINTS_COUNT)
        {
            uint16 index = 0;
            uint8 catIndex = 0;
            int8 previousCatIndex = 0;
            int8 catJobPointIndex = 0;

            while(Sql_NextRow(SqlHandle) == SQL_SUCCESS)
            {
                JobPoint_t JobPoint = {0};

                JobPoint.id = Sql_GetUIntData(SqlHandle, 0);
                JobPoint.catid = Sql_GetUIntData(SqlHandle, 1);
                JobPoint.jobid = Sql_GetUIntData(SqlHandle, 2);

                GJobPointsTemplate[index] = JobPoint;

                previousCatIndex = JobPoint.catid;

                if(previousCatIndex != catIndex)
                {
                    groupOffset[catIndex] = index - catJobPointIndex;
                    catIndex++;
                    catJobPointIndex = 0;

                    if(previousCatIndex != catIndex)
                    {
                        catIndex = previousCatIndex;
                    }
                }

                catJobPointIndex++;
                index++;
            }

            groupOffset[catIndex] = index - catJobPointIndex;
        }
        else
        {
            ShowError(CL_RED"The jobpoints table is damaged\n" CL_RESET);
        }
    };
}