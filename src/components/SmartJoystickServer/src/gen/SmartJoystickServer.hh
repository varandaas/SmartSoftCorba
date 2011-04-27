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

#ifndef _SMARTJOYSTICKSERVER_HH
#define _SMARTJOYSTICKSERVER_HH

#include <iostream>
#include "smartSoft.hh"
#include "../SmartJoystickServerCore.hh"
// include communication objects
#include <CommBasicObjects/commJoystick.hh>

// include tasks	

#include "../JoystickTask.hh"
// include handler
#include "../CompHandler.hh"

#define COMP SmartJoystickServer::instance()

class SmartJoystickServer: public SmartJoystickServerCore
{
private:
	static SmartJoystickServer _smartJoystickServer;

	// constructor
	SmartJoystickServer();

	// copy-constructor
	SmartJoystickServer(const SmartJoystickServer& cc);

	// destructor
	~SmartJoystickServer()
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

	JoystickTask joystickTask;

	// ports
	CHS::PushNewestServer<CommBasicObjects::CommJoystick> *joystickServer;

	void init(int argc, char *argv[]);
	void run();

	// return singleton instance
	static SmartJoystickServer* instance()
	{
		return (SmartJoystickServer*) &_smartJoystickServer;
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

		struct ini_joystickServer
		{
			std::string serviceName;
		} joystickServer;

		struct ini_general
		{

			bool verbose;
		} general;

		struct ini_hardware
		{

			std::string device;

			bool invert_y_axis;
		} hardware;

		struct ini_interval
		{

			double max;

			double min;
		} interval;
	} ini;

};
#endif