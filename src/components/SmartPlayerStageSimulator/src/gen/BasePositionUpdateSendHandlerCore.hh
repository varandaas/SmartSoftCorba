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

#ifndef _BASEPOSITIONUPDATESENDHANDLERCORE_HH
#define _BASEPOSITIONUPDATESENDHANDLERCORE_HH

#include "smartSoft.hh"

// include communication objects
#include <CommBasicObjects/commBasePositionUpdate.hh>

#include <CommBasicObjects/commBaseState.hh>

#include <CommBasicObjects/commMobileLaserScan.hh>

#include <CommBasicObjects/commNavigationVelocity.hh>

#include <CommBasicObjects/commVoid.hh>

class BasePositionUpdateSendHandlerCore: public CHS::SendServerHandler<
		CommBasicObjects::CommBasePositionUpdate>
{
public:
	void handleSend(const CommBasicObjects::CommBasePositionUpdate &r) throw()
	{
	}
	;
};
#endif
