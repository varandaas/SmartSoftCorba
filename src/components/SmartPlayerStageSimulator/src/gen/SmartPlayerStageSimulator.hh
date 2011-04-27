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

#ifndef _SMARTPLAYERSTAGESIMULATOR_HH
#define _SMARTPLAYERSTAGESIMULATOR_HH

#include <iostream>
#include "smartSoft.hh"
#include "../SmartPlayerStageSimulatorCore.hh"
// include communication objects
#include <CommBasicObjects/commBasePositionUpdate.hh>

#include <CommBasicObjects/commBaseState.hh>

#include <CommBasicObjects/commMobileLaserScan.hh>

#include <CommBasicObjects/commNavigationVelocity.hh>

#include <CommBasicObjects/commVoid.hh>

// include tasks	

// include handler
#include "../CompHandler.hh"
#include "../BasePositionUpdateSendHandler.hh"
#include "../BaseStateQueryHandler.hh"
#include "../NavigationVelocitySendServerHandler.hh"
#include "../PlayerPushTimedHandler.hh"

#define COMP SmartPlayerStageSimulator::instance()

class SmartPlayerStageSimulator: public SmartPlayerStageSimulatorCore
{
private:
	static SmartPlayerStageSimulator _smartPlayerStageSimulator;

	// constructor
	SmartPlayerStageSimulator();

	// copy-constructor
	SmartPlayerStageSimulator(const SmartPlayerStageSimulator& cc);

	// destructor
	~SmartPlayerStageSimulator()
	{
	}
	;

	// load parameter from ini file
	void loadParameter(int argc, char *argv[]);

	// instantiate handler
	CompHandler compHandler;
	BasePositionUpdateSendHandler basePositionUpdateSendHandler;
	BaseStateQueryHandler baseStateQueryHandler;
	NavigationVelocitySendServerHandler navigationVelocitySendServerHandler;
	PlayerPushTimedHandler playerPushTimedHandler;

	// ThreadQueueHandler 


public:
	// component
	CHS::SmartComponent *component;

	// create mutex
	CHS::SmartMutex PlayerClientMutex;
	CHS::SmartMutex RobotPosLock;

	// create condition mutex


	// instantiate tasks


	// ports
	CHS::PushTimedServer<CommBasicObjects::CommBaseState>
			*basePositionPushTimedServer;
	CHS::SendServer<CommBasicObjects::CommBasePositionUpdate>
			*basePositionUpdateSendServer;
	CHS::QueryServer<CommBasicObjects::CommVoid,
			CommBasicObjects::CommBaseState> *baseStateQueryServer;
	CHS::PushNewestServer<CommBasicObjects::CommMobileLaserScan> *laserServer;
	CHS::SendServer<CommBasicObjects::CommNavigationVelocity>
			*navigationVelocitySendServer;

	void init(int argc, char *argv[]);
	void run();

	// return singleton instance
	static SmartPlayerStageSimulator* instance()
	{
		return (SmartPlayerStageSimulator*) &_smartPlayerStageSimulator;
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

		struct ini_basePositionPushTimedServer
		{
			std::string serviceName;
			double cycle;
		} basePositionPushTimedServer;

		struct ini_basePositionUpdateSendServer
		{
			std::string serviceName;
		} basePositionUpdateSendServer;

		struct ini_baseStateQueryServer
		{
			std::string serviceName;
		} baseStateQueryServer;

		struct ini_laserServer
		{
			std::string serviceName;
		} laserServer;

		struct ini_navigationVelocitySendServer
		{
			std::string serviceName;
		} navigationVelocitySendServer;

	} ini;

};
#endif
