//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.10.0
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

#include "CompHandler.hh"
#include "gen/SmartGMapping.hh"

#include <iostream>

// include communication objects
#include <CommBasicObjects/commBasePositionUpdate.hh>

#include <CommBasicObjects/commMobileLaserScan.hh>

#include <CommNavigationObjects/commGMappingParameter.hh>

void CompHandler::onStartup()
{
	std::cout
			<< "startup - put your startupCode in CompHandler::onStartup()!!!\n";

	CHS::StatusCode status;

	// connect to all services
	std::cout << "connecting to: "
			<< COMP->ini.basePositionUpdateClient.serverName << "; "
			<< COMP->ini.basePositionUpdateClient.serviceName << std::endl;
	status = COMP->basePositionUpdateClient->connect(
			COMP->ini.basePositionUpdateClient.serverName,
			COMP->ini.basePositionUpdateClient.serviceName);
	while (status != CHS::SMART_OK)
	{
		usleep(500000);
		status = COMP->basePositionUpdateClient->connect(
				COMP->ini.basePositionUpdateClient.serverName,
				COMP->ini.basePositionUpdateClient.serviceName);
	}
	std::cout << "connected.\n";

	std::cout << "connecting to: " << COMP->ini.laserClient.serverName << "; "
			<< COMP->ini.laserClient.serviceName << std::endl;
	status = COMP->laserClient->connect(COMP->ini.laserClient.serverName,
			COMP->ini.laserClient.serviceName);
	while (status != CHS::SMART_OK)
	{
		usleep(500000);
		status = COMP->laserClient->connect(COMP->ini.laserClient.serverName,
				COMP->ini.laserClient.serviceName);
	}
	std::cout << "connected.\n";

	COMP->laserClient->subscribe();

	// activate state server
	if (COMP->stateServer->activate() != CHS::SMART_OK)
		std::cerr << "ERROR: activate state" << std::endl;

	// run all tasks
	COMP->gMappingTask.open();

}
