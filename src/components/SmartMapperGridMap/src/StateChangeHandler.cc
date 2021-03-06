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

#include "StateChangeHandler.hh"
#include "gen/SmartMapperGridMap.hh"

#include <iostream>

void StateChangeHandler::handleEnterState(const std::string & s) throw()
{
	std::cout << "    enterHandler  activate   " << s << std::endl;

}

void StateChangeHandler::handleQuitState(const std::string & s) throw()
{
	std::cout << "    quitHandler   deactivate " << s << std::endl;

}
