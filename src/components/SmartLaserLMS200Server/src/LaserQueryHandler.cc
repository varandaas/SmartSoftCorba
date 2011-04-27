//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.6.0
// The SmartSoft Toolchain has been developed by:
//
// ZAFH Servicerobotic Ulm
// Christian Schlegel (schlegel@hs-ulm.de)
// University of Applied Sciences
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// smart-robotics.sourceforge.net
//
// This file is generated once. Modify this file to your needs.
// If you want the workflow to re-generate this file, please
// delete it before running the workflow.
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
//
//  Copyright (C) 2003 Boris Kluge
//                2009 Andreas Steck
//
//        schlegel@hs-ulm.de
//
//        ZAFH Servicerobotic Ulm
//        University of Applied Sciences
//        Prittwitzstr. 10
//        89075 Ulm
//        Germany
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2.1
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along
//  with this library; if not, write to the Free Software Foundation, Inc.,
//  59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//--------------------------------------------------------------------------

#include "LaserQueryHandler.hh"
#include "gen/SmartLaserLMS200Server.hh"

#include <iostream>

void LaserQueryHandler::handleQuery(CHS::QueryServer<CommBasicObjects::CommVoid,
		CommBasicObjects::CommMobileLaserScan> & server, const CHS::QueryId id,
		const CommBasicObjects::CommVoid & request) throw ()
{
	CommBasicObjects::CommMobileLaserScan answer;

    COMP->ScanLock.acquire();
    answer = COMP->global_scan;
    COMP->ScanLock.release();

    //answer.set(result);
	server.answer(id, answer);
}