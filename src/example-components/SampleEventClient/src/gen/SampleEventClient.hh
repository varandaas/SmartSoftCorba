//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.8.0
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

#ifndef _SAMPLEEVENTCLIENT_HH
#define _SAMPLEEVENTCLIENT_HH

#include <iostream>
#include "smartSoft.hh"
#include "../SampleEventClientCore.hh"
// include communication objects
#include <CommSampleObjects/commSampleEvent1Parameter.hh>

#include <CommSampleObjects/commSampleEvent1Result.hh>

// include tasks	

#include "../MyEventTask.hh"
// include handler
#include "../CompHandler.hh"
#include "../MyEventHandler.hh"

#define COMP SampleEventClient::instance()

class SampleEventClient: public SampleEventClientCore
{
private:
	static SampleEventClient _sampleEventClient;

	// constructor
	SampleEventClient();

	// copy-constructor
	SampleEventClient(const SampleEventClient& cc);

	// destructor
	~SampleEventClient()
	{
	}
	;

	// load parameter from ini file
	void loadParameter(int argc, char *argv[]);

	// instantiate handler
	CompHandler compHandler;
	MyEventHandler myEventHandler;

	// ThreadQueueHandler 

public:
	// component
	CHS::SmartComponent *component;

	// create mutex


	// create condition mutex


	// instantiate tasks

	MyEventTask myEventTask;

	// ports
	CHS::EventClient<CommSampleObjects::CommSampleEvent1Parameter,
			CommSampleObjects::CommSampleEvent1Result> *eventClient1;
	CHS::EventClient<CommSampleObjects::CommSampleEvent1Parameter,
			CommSampleObjects::CommSampleEvent1Result> *eventClient2;

	void init(int argc, char *argv[]);
	void run();

	// return singleton instance
	static SampleEventClient* instance()
	{
		return (SampleEventClient*) &_sampleEventClient;
	}

	// ini parameter
	struct ini_ini
	{

		struct ini_eventClient1
		{
			std::string serverName;
			std::string serviceName;
		} eventClient1;

		struct ini_eventClient2
		{
			std::string serverName;
			std::string serviceName;
		} eventClient2;

	} ini;

};
#endif
