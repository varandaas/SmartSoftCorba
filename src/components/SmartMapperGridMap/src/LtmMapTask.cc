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

// --------------------------------------------------------------------------
//
//  Copyright (C) 2008 Christian Schlegel, Andreas Steck, Matthias Lutz
//
//        schlegel@hs-ulm.de
//        steck@hs-ulm.de
//
//        ZAFH Servicerobotik Ulm
//        University of Applied Sciences
//        Prittwitzstr. 10
//        D-89075 Ulm
//        Germany
//
//  This file is part of the "SmartSoft Mapper/GridMapper component".
//  It provides mapping services based on grid maps. The current map
//  represents the latest snapshot of the local surrounding based on
//  laserscans. The current map can be preoccupied by the longterm map.
//  The longterm map is a simple occupancy grid map.
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
//
// --------------------------------------------------------------------------

#include "LtmMapTask.hh"
#include "gen/SmartMapperGridMap.hh"

#include <iostream>

LtmMapTask::LtmMapTask()
{
	std::cout << "constructor LtmMapTask\n";
}

int LtmMapTask::svc()
{
	CommBasicObjects::CommMobileLaserScan laserscan;

	struct MapperStateStruct localState;
	int                      status;
	CHS::StatusCode          statusCode;

	while(1)
	{
		// ------------------------------------------------
	    // wait for activation
	    // ("buildltmmap")
	    // ------------------------------------------------
	    statusCode = COMP->stateServer->acquire("buildltmmap");
	    if (statusCode == CHS::SMART_OK)
	    {
	    	// wait for the next trigger
	    	COMP->LtmTriggerLock.acquire();
	    	COMP->MapperLtmTrigger.wait();
	    	COMP->LtmTriggerLock.release();


	    	// current map autoupdate service is activated
	    	COMP->MapperStateLock.acquire();
	    	localState = COMP->globalState;
	    	COMP->MapperStateLock.release();

	    	// wait for scan (PushNewest)
	    	status = COMP->laserClient->getUpdateWait(laserscan);
	    	if (status == CHS::SMART_OK)
	    	{
	    		COMP->LtmLock.acquire();
	    		COMP->ltmGridMap->update(laserscan, localState.ltmKalman);
	    		COMP->LtmLock.release();

	    		if(COMP->ini.general.verbose == true)
	    		{
	    			std::cout << "MAPPER: Updated LTM\n";
	    		}
	    	} // if (status == CHS::SMART_OK)
	    } // if (statusCode == CHS::SMART_OK)

	    // -----------------------------------------------------
	    // unlock state at end of while loop
	    // -----------------------------------------------------
	    statusCode = COMP->stateServer->release("buildltmmap");
	} // while(1)
	return 0;
} // svc longterm map
