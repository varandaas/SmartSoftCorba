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

#include "CompHandler.hh"
#include "gen/SmartLaserLMS200Server.hh"

#include <iostream>

// include communication objects


void CompHandler::onStartup()
{
	std::cout
			<< "startup - put your startupCode in CompHandler::onStartup()!!!\n";

	CHS::StatusCode status;

	// connect to all services
	if(COMP->ini.base.subscribe) {
		std::cout << "connecting to: " << COMP->ini.baseClient.serverName << "; "
				<< COMP->ini.baseClient.serviceName << std::endl;
		status = COMP->baseClient->connect(COMP->ini.baseClient.serverName,
				COMP->ini.baseClient.serviceName);
		while (status != CHS::SMART_OK)
		{
			usleep(500000);
			status = COMP->baseClient->connect(COMP->ini.baseClient.serverName,
					COMP->ini.baseClient.serviceName);
		}
		std::cout << "connected.\n";

		COMP->baseClient->subscribe(COMP->ini.baseClient.interval);
	} else {
		std::cout << "Not connecting to base." << std::endl;
	}

	// run all tasks
	COMP->laserTask.open();

}
