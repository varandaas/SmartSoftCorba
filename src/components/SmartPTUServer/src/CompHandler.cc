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
// If you want the toolchain to re-generate this file, please
// delete it before running the code generator.
//--------------------------------------------------------------------------
//------------------------------------------------------------------------
//
//  Copyright (C) 2010 Manuel Wopfner
//
//        wopfner@hs-ulm.de
//
//        Christian Schlegel (schlegel@hs-ulm.de)
//        University of Applied Sciences
//        Prittwitzstr. 10
//        89075 Ulm (Germany)
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//--------------------------------------------------------------------------
#include "CompHandler.hh"
#include "gen/SmartPTUServer.hh"

#include <iostream>

// include communication objects
#include <CommBasicObjects/commDevicePoseState.hh>

#include <CommPTUObjects/commPTUMoveRequest.hh>
#include <CommPTUObjects/commPTUMoveResponse.hh>
#include <CommPTUObjects/commPTUParameter.hh>

void CompHandler::onStartup() {
	CHS::StatusCode status;

	// connect to ptu unit
	if (COMP->ptu.init(COMP->ini.PTU.device)) {
		std::cout << "\n" << "Device: " << COMP->ini.PTU.device << " successfully connectd!\n";
	} else {
		std::cerr << "\n" << "ERROR: device " << COMP->ini.PTU.device << " could not be opened!\n";
	}

	// connect to all services
	if (COMP->ini.base.on_base) {
		std::cout << "connecting to: " << COMP->ini.baseStateQueryClient.serverName << "; "
				<< COMP->ini.baseStateQueryClient.serviceName << std::endl;
		status = COMP->baseStateQueryClient->connect(COMP->ini.baseStateQueryClient.serverName,
				COMP->ini.baseStateQueryClient.serviceName);
		while (status != CHS::SMART_OK) {
			usleep(500000);
			status = COMP->baseStateQueryClient->connect(COMP->ini.baseStateQueryClient.serverName,
					COMP->ini.baseStateQueryClient.serviceName);
		}
		std::cout << "connected.\n";


		std::cout << "connecting to: " << COMP->ini.baseStateClient.serverName << "; "
				<< COMP->ini.baseStateClient.serviceName << std::endl;
		status = COMP->baseStateClient->connect(COMP->ini.baseStateClient.serverName,
				COMP->ini.baseStateClient.serviceName);
		while (status != CHS::SMART_OK) {
			usleep(500000);
			status = COMP->baseStateClient->connect(COMP->ini.baseStateClient.serverName,
					COMP->ini.baseStateClient.serviceName);
		}
		std::cout << "connected.\n";

		COMP->baseStateClient->subscribe(COMP->ini.baseStateClient.interval);
	}

	// activate state server
	if (COMP->stateServer->activate() != CHS::SMART_OK)
		std::cerr << "ERROR: activate state" << std::endl;

	// run all tasks
	COMP->devicePoseStateTask.open();

	if (COMP->ini.base.on_base) {
		COMP->baseStateTask.open();
	}

}
