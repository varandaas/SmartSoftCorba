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

#include "Task1Timer.hh"
#include "SampleRTAIComp.hh"

#include <iostream>

void Task1Timer::timerExpired(const ACE_Time_Value & absolute_time,
		const void * arg)
{
	// signal condition mutex
	COMP->Task1Mutex.acquire();
	COMP->Task1CondMutex.signal();
	COMP->Task1Mutex.release();
}
