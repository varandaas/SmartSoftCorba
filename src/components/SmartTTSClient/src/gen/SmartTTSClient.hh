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

#ifndef _SMARTTTSCLIENT_HH
#define _SMARTTTSCLIENT_HH

#include <iostream>
#include "smartSoft.hh"
#include "../SmartTTSClientCore.hh"
// include communication objects
#include <CommBasicObjects/commPropertySet.hh>

#include <CommSpeechObjects/commSpeechOutputMessage.hh>

// include tasks	

#include "../ConsoleTask.hh"
// include handler
#include "../CompHandler.hh"

#define COMP SmartTTSClient::instance()

class SmartTTSClient: public SmartTTSClientCore
{
private:
	static SmartTTSClient _smartTTSClient;

	// constructor
	SmartTTSClient();

	// copy-constructor
	SmartTTSClient(const SmartTTSClient& cc);

	// destructor
	~SmartTTSClient()
	{
	}
	;

	// load parameter from ini file
	void loadParameter(int argc, char *argv[]);

	// instantiate handler
	CompHandler compHandler;

	// ThreadQueueHandler 

public:
	// component
	CHS::SmartComponent *component;

	// create mutex


	// create condition mutex


	// instantiate tasks

	ConsoleTask consoleTask;

	// ports
	CHS::QueryClient<CommSpeechObjects::CommSpeechOutputMessage,
			CommBasicObjects::CommPropertySet> *queryClient;
	CHS::SendClient<CommSpeechObjects::CommSpeechOutputMessage> *sendClient;

	void init(int argc, char *argv[]);
	void run();

	// return singleton instance
	static SmartTTSClient* instance()
	{
		return (SmartTTSClient*) &_smartTTSClient;
	}

	// ini parameter
	struct ini_ini
	{

		// component struct
		struct ini_component
		{
			// the name of the component
			std::string name;
		} component;

		struct ini_queryClient
		{
			std::string serverName;
			std::string serviceName;
		} queryClient;

		struct ini_sendClient
		{
			std::string serverName;
			std::string serviceName;
		} sendClient;

	} ini;

};
#endif
