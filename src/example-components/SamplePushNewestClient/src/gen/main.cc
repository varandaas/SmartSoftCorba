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
// Please do not modify this file. It will be re-generated
// running the code generator.
//--------------------------------------------------------------------------

#include <iostream>
#include "SamplePushNewestClient.hh"

SamplePushNewestClient SamplePushNewestClient::_samplePushNewestClient;

int main(int argc, char *argv[])
{
	std::cout << "main...\n";
	SamplePushNewestClient::instance()->init(argc, argv);
	SamplePushNewestClient::instance()->run();
}

