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

#define GetJobPointCategory(jp) ((jp >> 6) - 1)
#define GetJobPointID(jp)       ((jp & 0x3F) >> 1)


namespace jobpointutils
{
	JobPoint_t  GJobPointssTemplate[JOBPOINTS_COUNT] = {0};	// global list of jobpoints
	int16       groupOffset[JPCATEGORY_COUNT] = {0};		// the first jp of each job

    void LoadJobPointsList()
    {
        return;
    }
}