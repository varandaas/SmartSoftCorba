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

#ifndef _OPENRAVECORE_HH
#define _OPENRAVECORE_HH

#include "smartSoft.hh"

// include communication objects
#include <commMoMaManipulateState.hh>
#include <commMoMaObjectList.hh>
#include <commMoMaPose.hh>
#include <commMoMaScanEnvironment.hh>

class OpenRaveCore: public CHS::QueryServerHandler<Smart::CommMoMaObjectList,
		Smart::CommMoMaManipulateState>
{
public:
	void handleQuery(CHS::QueryServer<Smart::CommMoMaObjectList,
			Smart::CommMoMaManipulateState> & server, const CHS::QueryId id,
			const Smart::CommMoMaObjectList & request) throw()
	{
	}
	;
};
#endif
