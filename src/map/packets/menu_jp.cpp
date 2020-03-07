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

#include "../../common/socket.h"

#include "menu_jp.h"

#include "../entities/charentity.h"
#include "../utils/charutils.h"


CMenuJobPointsPacket::CMenuJobPointsPacket(CCharEntity* PChar) 
{
	this->type = 0x63;
	this->size = 0x9c;
	
	ref<uint8>(0x04) = 0x05;
	ref<uint8>(0x06) = 0x98;

    ref<uint8>(0x08) = 0x1; // 0x0 for no access, 0x1 for access
    ref<uint8>(0x0A) = 0x0;

	//TODO: Add Job iteration unit8 CP, uint8 JP, uint8 SPENT, 0X0c is always 0'd
}




//0x63, 0x06, 0x88, 0x41, 0x02, 0x00, 0x08, 0x00, 0xD3, 0x03, 0x03, 0x60