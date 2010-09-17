//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.6.0
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

#include "SmartKatanaServer.hh"

// constructor
SmartKatanaServer::SmartKatanaServer()
{
	std::cout << "constructor SmartKatanaServer\n";

	ini.scan3dEventServer.serviceName = "newScan";
	ini.trajectorySendServer.serviceName = "performTrajectory";
	ini.requestScan3dSendServer.serviceName = "request3dscan";
	ini.stateServer.serviceName = "stateServer";
	ini.scan3dQueryServer.serviceName = "3dscan";
	ini.eventServer.serviceName = "eventServer";
	ini.paramServer.serviceName = "param";
	ini.posePushTimedServer.serviceName = "currentPose";
	ini.posePushTimedServer.cycle = 0.1;
	ini.basePushTimedClient.serverName = "smartPioneerBaseServer";
	ini.basePushTimedClient.serviceName = "basestate";
	ini.basePushTimedClient.interval = 1;
	ini.laserQueryClient.serverName = "SmartLaserHokuyoURGServer";
	ini.laserQueryClient.serviceName = "scan";
	ini.laserStateClient.serverName = "SmartLaserHokuyoURGServer";
	ini.laserStateClient.serviceName = "stateServer";
	ini.katana.y = 0;
	ini.katana.x = 0;
	ini.katana.goal_position_approach = 3;
	ini.katana.azimuth = 0;
	ini.katana.fast_calibration = false;
	ini.katana.z = 0;
	ini.katana.goal_angle_approach = 0.1;
	ini.katana.katana_config_file = "src/config/katana6M180.cfg";
	ini.katana.elevation = 0;
	ini.katana.katana_device = "Serial";
	ini.katana.verbose = false;
	ini.katana.roll = 0;
	ini.laser.azimuth = 0;
	ini.laser.laser_is_mounted = false;
	ini.laser.z = 0;
	ini.laser.y = 0;
	ini.laser.x = 0;
	ini.laser.elevation = 0;
	ini.laser.high_precision = true;
	ini.laser.roll = 0;
	ini.base.turret_a = 0;
	ini.base.on_base = true;
	ini.base.steer_a = 0;
	ini.base.y = 0;
	ini.base.x = 0;
	ini.base.base_a = 0;
	ini.base.z = 0;
	ini.serial_port.device = "/dev/ttyS0";
	ini.network.port = 5566;
	ini.network.ip_adress = "127.0.0.1";
}

void SmartKatanaServer::init(int argc, char *argv[])
{
	try
	{
		component = new CHS::SmartComponent("SmartKatanaServer", argc, argv);
		loadParameter(argc, argv);

		// create ports
		scan3dEventServer = new CHS::EventServer<Smart::CommVoid,
				Smart::CommManipulatorId, Smart::ScanEventState>(component,
				ini.scan3dEventServer.serviceName, scanEventTestHandler);

		threadTrajectorySendHandler = new CHS::ThreadQueueSendHandler<
				Smart::CommManipulatorTrajectory>(trajectorySendHandler);
		trajectorySendServer = new CHS::SendServer<
				Smart::CommManipulatorTrajectory>(component,
				ini.trajectorySendServer.serviceName,
				*threadTrajectorySendHandler);

		threadRequestScan3dHandler = new CHS::ThreadQueueSendHandler<
				Smart::CommManipulatorRequestScan3d>(requestScan3dHandler);
		requestScan3dSendServer = new CHS::SendServer<
				Smart::CommManipulatorRequestScan3d>(component,
				ini.requestScan3dSendServer.serviceName,
				*threadRequestScan3dHandler);

		basePushTimedClient = new CHS::PushTimedClient<Smart::CommBaseState>(
				component);
		stateServer = new CHS::SmartStateServer(component,
				ini.stateServer.serviceName, stateChangeHandler);
		// define states for stateServer (CHS::SmartStateServer) 
		if (stateServer->defineStates("scan", "scan") != CHS::SMART_OK)
			std::cerr << "ERROR: define state" << std::endl;
		if (stateServer->defineStates("demonstration", "demonstration")
				!= CHS::SMART_OK)
			std::cerr << "ERROR: define state" << std::endl;
		if (stateServer->defineStates("trajectory", "trajectory")
				!= CHS::SMART_OK)
			std::cerr << "ERROR: define state" << std::endl;
		threadScan3dHandler = new CHS::ThreadQueueQueryHandler<
				Smart::CommManipulatorId, Smart::Comm3dPointCloud>(
				scan3dHandler);
		scan3dQueryServer = new CHS::QueryServer<Smart::CommManipulatorId,
				Smart::Comm3dPointCloud>(component,
				ini.scan3dQueryServer.serviceName, *threadScan3dHandler);

		eventServer
				= new CHS::EventServer<Smart::CommManipulatorEventParameter,
						Smart::CommManipulatorEventResult,
						Smart::ManipulatorEventState>(component,
						ini.eventServer.serviceName, eventTestHandler);
		laserQueryClient = new CHS::QueryClient<Smart::CommVoid,
				Smart::CommMobileLaserScan>(component);
		laserStateClient = new CHS::SmartStateClient(component);

		paramServer = new CHS::SendServer<Smart::CommManipulatorParameter>(
				component, ini.paramServer.serviceName, paramHandler);

		posePushTimedServer = new CHS::PushTimedServer<
				Smart::CommMobileManipulatorState>(component,
				ini.posePushTimedServer.serviceName, posePushTimedHandler,
				ini.posePushTimedServer.cycle);

	} catch (const CORBA::Exception &)
	{
		std::cerr << "Uncaught CORBA exception" << std::endl;
	} catch (...)
	{
		std::cerr << "Uncaught exception" << std::endl;
	}
}

// run the component
void SmartKatanaServer::run()
{
	compHandler.onStartup();
	component->run();
	delete component;
}

void SmartKatanaServer::loadParameter(int argc, char *argv[])
{
	/* 
	 Parameters can be specified via command line -filename=<filename>
	 
	 With this parameter present:
	 - The component will look for the file in the current working directory, 
	 a path relative to the current directory or any absolute path
	 - The component will use the default values if the file cannot be found
	 
	 With this parameter absent:
	 - <Name of Component>.ini will be read from current working directory, if found there
	 - $SMART_ROOT/etc/<Name of Component>.ini will be read otherwise
	 - Default values will be used if neither found in working directory or /etc   
	 */
	CHS::SmartParameter parameter;

	// load parameters
	try
	{
		// check if paramfile is given as argument
		bool paramFile = false;
		std::string str;
		for (int i = 0; i < argc; i++)
		{
			str = argv[i];
			if (str.find("filename") != std::string::npos)
				paramFile = true;
		}

		// if paramfile is given as argument
		if (paramFile == true)
		{
			std::cout << "load parameter file from argv \n";
			parameter.addFile(argc, argv, "filename", false);
		}
		// else load standard paramfile
		else
		{
			std::cout << "load SmartKatanaServer.ini parameter file\n";
			parameter.addFile("SmartKatanaServer.ini");
		}

		// than add command line arguments to allow overwriting of parameters
		// from file
		parameter.addCommandLine("", argc, argv);

		// print all known parameters
		parameter.print(); // TODO remove this


		// load parameter
		parameter.getString("scan3dEventServer", "serviceName",
				ini.scan3dEventServer.serviceName);
		parameter.getString("trajectorySendServer", "serviceName",
				ini.trajectorySendServer.serviceName);
		parameter.getString("requestScan3dSendServer", "serviceName",
				ini.requestScan3dSendServer.serviceName);
		parameter.getString("stateServer", "serviceName",
				ini.stateServer.serviceName);
		parameter.getString("scan3dQueryServer", "serviceName",
				ini.scan3dQueryServer.serviceName);
		parameter.getString("eventServer", "serviceName",
				ini.eventServer.serviceName);
		parameter.getString("paramServer", "serviceName",
				ini.paramServer.serviceName);
		parameter.getString("posePushTimedServer", "serviceName",
				ini.posePushTimedServer.serviceName);
		parameter.getDouble("posePushTimedServer", "cycle",
				ini.posePushTimedServer.cycle);
		parameter.getString("basePushTimedClient", "serverName",
				ini.basePushTimedClient.serverName);
		parameter.getString("basePushTimedClient", "serviceName",
				ini.basePushTimedClient.serviceName);
		parameter.getInt("basePushTimedClient", "interval",
				ini.basePushTimedClient.interval);
		parameter.getString("laserQueryClient", "serverName",
				ini.laserQueryClient.serverName);
		parameter.getString("laserQueryClient", "serviceName",
				ini.laserQueryClient.serviceName);
		parameter.getString("laserStateClient", "serverName",
				ini.laserStateClient.serverName);
		parameter.getString("laserStateClient", "serviceName",
				ini.laserStateClient.serviceName);
		parameter.getInt("katana", "y", ini.katana.y);
		parameter.getInt("katana", "x", ini.katana.x);
		parameter.getDouble("katana", "goal_position_approach",
				ini.katana.goal_position_approach);
		parameter.getDouble("katana", "azimuth", ini.katana.azimuth);
		parameter.getTruthValue("katana", "fast_calibration",
				ini.katana.fast_calibration);
		parameter.getInt("katana", "z", ini.katana.z);
		parameter.getDouble("katana", "goal_angle_approach",
				ini.katana.goal_angle_approach);
		parameter.getString("katana", "katana_config_file",
				ini.katana.katana_config_file);
		parameter.getDouble("katana", "elevation", ini.katana.elevation);
		parameter.getString("katana", "katana_device", ini.katana.katana_device);
		parameter.getTruthValue("katana", "verbose", ini.katana.verbose);
		parameter.getDouble("katana", "roll", ini.katana.roll);
		parameter.getDouble("laser", "azimuth", ini.laser.azimuth);
		parameter.getTruthValue("laser", "laser_is_mounted",
				ini.laser.laser_is_mounted);
		parameter.getInt("laser", "z", ini.laser.z);
		parameter.getInt("laser", "y", ini.laser.y);
		parameter.getInt("laser", "x", ini.laser.x);
		parameter.getDouble("laser", "elevation", ini.laser.elevation);
		parameter.getTruthValue("laser", "high_precision",
				ini.laser.high_precision);
		parameter.getDouble("laser", "roll", ini.laser.roll);
		parameter.getDouble("base", "turret_a", ini.base.turret_a);
		parameter.getTruthValue("base", "on_base", ini.base.on_base);
		parameter.getDouble("base", "steer_a", ini.base.steer_a);
		parameter.getInt("base", "y", ini.base.y);
		parameter.getInt("base", "x", ini.base.x);
		parameter.getDouble("base", "base_a", ini.base.base_a);
		parameter.getInt("base", "z", ini.base.z);
		parameter.getString("serial_port", "device", ini.serial_port.device);
		parameter.getInt("network", "port", ini.network.port);
		parameter.getString("network", "ip_adress", ini.network.ip_adress);

	} catch (const CORBA::Exception &)
	{
		std::cerr << "Uncaught CORBA exception" << std::endl;
	} catch (const CHS::ParameterError & e)
	{
		std::cerr << "Exception from parameter handling: " << e << std::endl;
	} catch (...)
	{
		std::cerr << "Uncaught exception" << std::endl;
	}
}

