//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.2.1
// The SmartSoft Toolchain has been developed by:
//  
// ZAFH Servicerobotic Ulm
// Christian Schlegel (schlegel@hs-ulm.de)
// University of Applied Sciences
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// http://smart-robotics.sourceforge.net/
// 
// Please do not modify this file. It will be re-generated
// running the workflow.
//--------------------------------------------------------------------------

#include <iostream>
#include "MobileManipulationServer.hh"

MobileManipulationServer MobileManipulationServer::_mobileManipulationServer;

int main(int argc, char *argv[])
{
	std::cout << "main...\n";
	MobileManipulationServer::instance()->init(argc, argv);
	MobileManipulationServer::instance()->run();
}

