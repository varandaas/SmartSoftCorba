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

#ifndef _PLANNERTRIGGERTIMER_HH
#define _PLANNERTRIGGERTIMER_HH

#include "smartSoft.hh"

#include "gen/PlannerTriggerTimerCore.hh"

class PlannerTriggerTimer: public PlannerTriggerTimerCore
{
	virtual void timerExpired(const ACE_Time_Value & absolute_time,
			const void * arg);
};

#endif
