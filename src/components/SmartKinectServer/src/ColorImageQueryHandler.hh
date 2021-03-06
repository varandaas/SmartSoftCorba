//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.10.3
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

#ifndef _COLORIMAGEQUERYHANDLER_HH
#define _COLORIMAGEQUERYHANDLER_HH

#include "smartSoft.hh"

// include communication objects
#include <CommBasicObjects/commBaseState.hh>

#include <CommBasicObjects/commDevicePoseState.hh>

#include <CommBasicObjects/commVoid.hh>

#include <CommVisionObjects/commKinectImage.hh>

#include <CommVisionObjects/commVideoImage.hh>

#include "gen/ColorImageQueryHandlerCore.hh"

class ColorImageQueryHandler: public ColorImageQueryHandlerCore
{
	void handleQuery(CHS::QueryServer<CommBasicObjects::CommVoid,
			CommVisionObjects::CommVideoImage> & server, const CHS::QueryId id,
			const CommBasicObjects::CommVoid & request) throw();
};

#endif
