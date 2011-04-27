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

#ifndef _SMARTKINECTTESTCLIENT_HH
#define _SMARTKINECTTESTCLIENT_HH

#include <iostream>
#include "smartSoft.hh"
#include "../SmartKinectTestClientCore.hh"
// include communication objects
#include <CommVisionObjects/commKinectImage.hh>

// include tasks	

#include "../ViewerTask.hh"
// include handler
#include "../CompHandler.hh"

#define COMP SmartKinectTestClient::instance()

class SmartKinectTestClient: public SmartKinectTestClientCore
{
private:
	static SmartKinectTestClient _smartKinectTestClient;

	// constructor
	SmartKinectTestClient();

	// copy-constructor
	SmartKinectTestClient(const SmartKinectTestClient& cc);

	// destructor
	~SmartKinectTestClient()
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

	ViewerTask viewerTask;

	// ports
	CHS::PushNewestClient<CommVisionObjects::CommKinectImage>
			*imagePushNewestClient;
	CHS::SmartStateClient *stateClient;

	void init(int argc, char *argv[]);
	void run();

	// return singleton instance
	static SmartKinectTestClient* instance()
	{
		return (SmartKinectTestClient*) &_smartKinectTestClient;
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

		struct ini_imagePushNewestClient
		{
			std::string serverName;
			std::string serviceName;
		} imagePushNewestClient;

		struct ini_stateClient
		{
			std::string serverName;
			std::string serviceName;
		} stateClient;

	} ini;

};
#endif
