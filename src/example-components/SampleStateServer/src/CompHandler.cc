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
#include "gen/SampleStateServer.hh"

#include <iostream>

// include communication objects

void CompHandler::onStartup()
{
	std::cout
			<< "startup - put your startupCode in CompHandler::onStartup()!!!\n";

	// activate state server
	if (COMP->stateServer->activate() != CHS::SMART_OK)
		std::cerr << "ERROR: activate state" << std::endl;

	// run all tasks
	COMP->myTask.open();

}