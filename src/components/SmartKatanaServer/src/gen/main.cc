//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.10.2
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
// Please do not modify this file. It will be re-generated
// running the code generator.
//--------------------------------------------------------------------------

#include <iostream>
#include "SmartKatanaServer.hh"

SmartKatanaServer SmartKatanaServer::_smartKatanaServer;

int main(int argc, char *argv[])
{
	std::cout << "main...\n";
	SmartKatanaServer::instance()->init(argc, argv);
	SmartKatanaServer::instance()->run();
}

