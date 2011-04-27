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

#ifndef _SMARTKINECTSERVER_HH
#define _SMARTKINECTSERVER_HH

#include <iostream>
#include "smartSoft.hh"
#include "../SmartKinectServerCore.hh"
// include communication objects
#include <CommBasicObjects/commBaseState.hh>

#include <CommBasicObjects/commVoid.hh>

#include <CommVisionObjects/commKinectImage.hh>

// include tasks	

#include "../ImageTask.hh"
// include handler
#include "../CompHandler.hh"
#include "../ImageQueryHandler.hh"
#include "ImageTaskTimer.hh"
#include "../StateChangeHandler.hh"

#define COMP SmartKinectServer::instance()

class SmartKinectServer: public SmartKinectServerCore
{
private:
	static SmartKinectServer _smartKinectServer;

	// constructor
	SmartKinectServer();

	// copy-constructor
	SmartKinectServer(const SmartKinectServer& cc);

	// destructor
	~SmartKinectServer()
	{
	}
	;

	// load parameter from ini file
	void loadParameter(int argc, char *argv[]);

	// instantiate handler
	CompHandler compHandler;
	ImageQueryHandler imageQueryHandler;
	ImageTaskTimer imageTaskTimer;
	StateChangeHandler stateChangeHandler;

	// ThreadQueueHandler 


public:
	// component
	CHS::SmartComponent *component;

	// create mutex
	CHS::SmartMutex ImageTaskMutex;
	CHS::SmartMutex NewestImageMutex;

	// create condition mutex
	CHS::SmartConditionMutex ImageTaskCondMutex;//(ImageTaskMutex);


	// instantiate tasks

	ImageTask imageTask;

	// ports
	CHS::PushTimedClient<CommBasicObjects::CommBaseState> *basePushTimedClient;
	CHS::PushNewestServer<CommVisionObjects::CommKinectImage>
			*imagePushNewestServer;
	CHS::QueryServer<CommBasicObjects::CommVoid,
			CommVisionObjects::CommKinectImage> *imageQueryServer;
	CHS::SmartStateServer *stateServer;

	void init(int argc, char *argv[]);
	void run();

	// return singleton instance
	static SmartKinectServer* instance()
	{
		return (SmartKinectServer*) &_smartKinectServer;
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

		struct ini_imagePushNewestServer
		{
			std::string serviceName;
		} imagePushNewestServer;

		struct ini_imageQueryServer
		{
			std::string serviceName;
		} imageQueryServer;

		struct ini_stateServer
		{
			std::string serviceName;
		} stateServer;

		struct ini_basePushTimedClient
		{
			std::string serverName;
			std::string serviceName;
			long interval;
		} basePushTimedClient;

		struct ini_base
		{

			double base_a;

			bool on_base;

			double steer_a;

			double turret_a;

			long x;

			long y;

			long z;
		} base;

		struct ini_component
		{

			bool debug_info;

			bool push_newest_active;

			double valid_image_time;
		} component;

		struct ini_hardware_properties
		{

			unsigned long height;

			double max_distance;

			double min_distance;

			unsigned long width;
		} hardware_properties;

		struct ini_sensor_pose
		{

			double azimuth;

			double elevation;

			double roll;

			double x;

			double y;

			double z;
		} sensor_pose;
	} ini;

};
#endif
