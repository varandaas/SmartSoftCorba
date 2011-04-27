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

#ifndef _EVENTTESTHANDLERCORE_HH
#define _EVENTTESTHANDLERCORE_HH

#include "smartSoft.hh"

// include communication objects
#include <CommSpeechObjects/commSpeechInputEventParameter.hh>

#include <CommSpeechObjects/commSpeechInputEventResult.hh>

#include <CommSpeechObjects/commSpeechInputParameter.hh>

#include <CommSpeechObjects/speechInputEventState.hh>

class EventTestHandlerCore: public CHS::EventTestHandler<
		CommSpeechObjects::CommSpeechInputEventParameter,
		CommSpeechObjects::CommSpeechInputEventResult,
		CommSpeechObjects::SpeechInputEventState>
{
public:
	bool testEvent(CommSpeechObjects::CommSpeechInputEventParameter &p,
			CommSpeechObjects::CommSpeechInputEventResult &r,
			const CommSpeechObjects::SpeechInputEventState &s) throw()
	{
		return false;
	}
	;
};
#endif
