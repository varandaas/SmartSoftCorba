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

#ifndef _PARAMETERHANDLER_HH
#define _PARAMETERHANDLER_HH

#include "smartSoft.hh"

#include "CommNavigationObjects/commMapperParameter.hh"

#include "gen/ParameterHandlerCore.hh"

class ParameterHandler: public ParameterHandlerCore
{
	void handleSend(const CommNavigationObjects::CommMapperParameter &r) throw();
};

#endif
