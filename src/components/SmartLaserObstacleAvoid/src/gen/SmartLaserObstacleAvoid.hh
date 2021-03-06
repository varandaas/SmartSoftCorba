//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.10.4
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

#ifndef _SMARTLASEROBSTACLEAVOID_HH
#define _SMARTLASEROBSTACLEAVOID_HH

#include <iostream>
#include "smartSoft.hh"
#include "../SmartLaserObstacleAvoidCore.hh"
// include communication objects
#include <CommBasicObjects/commMobileLaserScan.hh>
#include <CommBasicObjects/commNavigationVelocity.hh>
// include tasks	

#include "../RobotTask.hh"
// include handler
#include "../CompHandler.hh"

#define COMP SmartLaserObstacleAvoid::instance()

class SmartLaserObstacleAvoid: public SmartLaserObstacleAvoidCore
{
private:
	static SmartLaserObstacleAvoid _smartLaserObstacleAvoid;

	// constructor
	SmartLaserObstacleAvoid();

	// copy-constructor
	SmartLaserObstacleAvoid(const SmartLaserObstacleAvoid& cc);

	// destructor
	~SmartLaserObstacleAvoid()
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

	RobotTask robotTask;

	// ports
	CHS::PushNewestClient<CommBasicObjects::CommMobileLaserScan> *laserClient;
	CHS::SendClient<CommBasicObjects::CommNavigationVelocity>
			*navigationVelocitySendClient;
	CHS::WiringSlave *wiringSlave;

	void init(int argc, char *argv[]);
	void run();

	// return singleton instance
	static SmartLaserObstacleAvoid* instance()
	{
		return (SmartLaserObstacleAvoid*) &_smartLaserObstacleAvoid;
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

		struct ini_laserClient
		{
			std::string serverName;
			std::string serviceName;
		} laserClient;

		struct ini_navigationVelocitySendClient
		{
			std::string serverName;
			std::string serviceName;
		} navigationVelocitySendClient;

	} ini;

};
#endif
