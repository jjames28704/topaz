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
#include "entities/battleentity.h"

CJobPoints::CJobPoints(CCharEntity* PChar)
{
    jp_PChar = PChar;
    this->LoadJobPoints();
}

void CJobPoints::LoadJobPoints()
{
    memset(job_points, 0, sizeof(job_points));
    if (
        Sql_Query(SqlHandle, "SELECT charid, jobid, capacity_points, job_points, job_points_spent, "
                            "jptype0, jptype1, jptype2, jptype3, jptype4, jptype5, jptype6, jptype7, jptype8, jptype9 "
                            "FROM char_job_points WHERE charid = %u ORDER BY jobid ASC", jp_PChar->id) != SQL_ERROR
    ){
        for(uint8 i = 0; i < Sql_NumRows(SqlHandle); i++) {
            if(Sql_NextRow(SqlHandle) == SQL_SUCCESS) {
                uint32 jobid = Sql_GetUIntData(SqlHandle, 1);
                uint16 job_category = JOBPOINTS_CATEGORY_BY_JOBID(jobid);
                JobPoints_t current_job = {}; 
                current_job.jobid = jobid;
                current_job.job_category = job_category;
                current_job.capacity_points = Sql_GetUIntData(SqlHandle, 2);
                current_job.job_points = Sql_GetUIntData(SqlHandle, 3);
                current_job.job_points_spent = Sql_GetUIntData(SqlHandle, 4);
                for(uint8 j = 0; j < JOBPOINTS_JPTYPE_PER_CATEGORY; j++) {
                    JobPointType_t current_type = {};
                    current_type.id = current_job.job_category + j;
                    current_type.value = Sql_GetUIntData(SqlHandle, JOBPOINTS_SQL_COLUMN_OFFSET + j);
                    memcpy(&current_job.job_point_types[j], &current_type, sizeof(JobPointType_t));
                }
                memcpy(&job_points[jobid], &current_job, sizeof(JobPoints_t));
            }
        }
    }
}

bool CJobPoints::IsJobPointExist(JOBPOINT_TYPE jp_type)
{
    if((int16)jp_type < JOBPOINTS_CATEGORY_START) return false;
    if((JOBPOINTS_CATEGORY_BY_JPTYPE(jp_type) - 1) > JOBPOINTS_CATEGORY_COUNT) return false;
    if(JOBPOINTS_JPTYPE_INDEX(jp_type) > JOBPOINTS_JPTYPE_PER_CATEGORY) return false;

    return true;
}

JobPoints_t* CJobPoints::GetJobPointsByType(JOBPOINT_TYPE jp_type) {
    if (IsJobPointExist(jp_type))
    {
        return &job_points[JOBPOINTS_CATEGORY_BY_JPTYPE(jp_type)];
    }
    return nullptr;
}

JobPointType_t* CJobPoints::GetJobPointType(JOBPOINT_TYPE jp_type)
{
    if (IsJobPointExist(jp_type))
    {
        return &job_points[JOBPOINTS_CATEGORY_BY_JPTYPE(jp_type)].job_point_types[JOBPOINTS_JPTYPE_INDEX(jp_type)];
    }
    return nullptr;
}

void CJobPoints::RaiseJobPoint(JOBPOINT_TYPE jp_type)
{
    JobPoints_t* job = GetJobPointsByType(jp_type);
    JobPointType_t* job_point = GetJobPointType(jp_type);

    uint8 cost = JOBPOINTS_NEXT_COST(job_point->value);
    if(cost != 0 && job->job_points >= cost) 
    {
        job->job_points -= cost;
        job->job_points_spent += cost;
        job_point->value += 1;
        Sql_Query(SqlHandle, "UPDATE char_job_points SET jptype%u='%u', job_points='%u', job_points_spent='%u' WHERE charid='%u' AND jobid='%u'", 
            JOBPOINTS_JPTYPE_INDEX(job_point->id), job_point->value, job->job_points, job->job_points_spent, jp_PChar->id, job->jobid);
    }

}

JobPoints_t* CJobPoints::GetAllJobPoints()
{
    return job_points;
}

namespace jobpointutils
{
    void LoadJobPointsList()
    {

    };
}