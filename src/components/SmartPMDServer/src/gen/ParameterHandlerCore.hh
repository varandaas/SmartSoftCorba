//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.10.4
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

#ifndef _PARAMETERHANDLERCORE_HH
#define _PARAMETERHANDLERCORE_HH

#include "smartSoft.hh"

// include communication objects
#include <CommBasicObjects/commBaseState.hh>

#include <CommBasicObjects/commDevicePoseState.hh>

#include <CommBasicObjects/commVoid.hh>

#include <CommVisionObjects/commToFImage.hh>

#include <CommVisionObjects/commToFParameter.hh>

class ParameterHandlerCore: public CHS::SendServerHandler<
		CommVisionObjects::CommToFParameter>
{
public:
	void handleSend(const CommVisionObjects::CommToFParameter &r) throw()
	{
	}
	;
};
#endif
