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

#ifndef _TASK1TIMER_HH
#define _TASK1TIMER_HH

#include "smartSoft.hh"

#include "Task1TimerCore.hh"

class Task1Timer: public Task1TimerCore
{
	virtual void timerExpired(const ACE_Time_Value & absolute_time,
			const void * arg);
};

#endif
