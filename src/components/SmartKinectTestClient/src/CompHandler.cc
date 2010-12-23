//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.8.0
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
#include "gen/SmartKinectTestClient.hh"

#include <iostream>

// include communication objects
#include <CommKinectObjects/commKinectImage.hh>

void CompHandler::onStartup() {
	std::cout << "startup - put your startupCode in CompHandler::onStartup()!!!\n";

	CHS::StatusCode status;

	// connect to all services
	std::cout << "connecting to: " << COMP->ini.stateClient.serverName << "; " << COMP->ini.stateClient.serviceName
			<< std::endl;
	status = COMP->stateClient->connect(COMP->ini.stateClient.serverName, COMP->ini.stateClient.serviceName);
	while (status != CHS::SMART_OK) {
		usleep(500000);
		status = COMP->stateClient->connect(COMP->ini.stateClient.serverName, COMP->ini.stateClient.serviceName);
	}
	std::cout << "connected.\n";

	std::cout << "connecting to: " << COMP->ini.imagePushNewestClient.serverName << "; "
			<< COMP->ini.imagePushNewestClient.serviceName << std::endl;
	status = COMP->imagePushNewestClient->connect(COMP->ini.imagePushNewestClient.serverName,
			COMP->ini.imagePushNewestClient.serviceName);
	while (status != CHS::SMART_OK) {
		usleep(500000);
		status = COMP->imagePushNewestClient->connect(COMP->ini.imagePushNewestClient.serverName,
				COMP->ini.imagePushNewestClient.serviceName);
	}
	std::cout << "connected.\n";

	COMP->imagePushNewestClient->subscribe();

	// run all tasks
	COMP->viewerTask.open();

}
