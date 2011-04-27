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

#include "SmartPTUServer.hh"

// constructor
SmartPTUServer::SmartPTUServer()
{
	std::cout << "constructor of SmartPTUServer\n";

	ini.component.name = "SmartPTUServer";

	ini.devicePoseStateServer.serviceName = "devicePoseState";
	ini.moveQueryServer.serviceName = "movePTU";
	ini.paramServer.serviceName = "param";
	ini.stateServer.serviceName = "state";
	ini.baseStateClient.serverName = "SmartPioneerBaseServer";
	ini.baseStateClient.serviceName = "basestate";
	ini.baseStateClient.interval = 100;
	ini.baseStateQueryClient.serverName = "SmartPioneerBaseServer";
	ini.baseStateQueryClient.serviceName = "basestatequery";
	ini.PTU.azimuth = 0;
	ini.PTU.device = "/dev/ttyS0";
	ini.PTU.elevation = 0;
	ini.PTU.roll = 0;
	ini.PTU.verbose = false;
	ini.PTU.x = 0;
	ini.PTU.y = 0;
	ini.PTU.z = 0;
	ini.base.base_a = 0;
	ini.base.on_base = true;
	ini.base.steer_a = 0;
	ini.base.turret_a = 0;
	ini.base.x = 0;
	ini.base.y = 0;
	ini.base.z = 0;
	ini.hardware.acceleration_pan = 1.795;
	ini.hardware.acceleration_tilt = 1.795;
	ini.hardware.max_speed_pan = 2.604;
	ini.hardware.max_speed_tilt = 2.604;
	ini.hardware.min_speed_pan = 0.028;
	ini.hardware.min_speed_tilt = 0.028;
	ini.hardware.speed_pan = 1.0;
	ini.hardware.speed_tilt = 1.0;
	ini.hardware.start_up_speed_pan = 0.2;
	ini.hardware.start_up_speed_tilt = 0.2;
}

void SmartPTUServer::init(int argc, char *argv[])
{
	try
	{
		loadParameter(argc, argv);
		component = new CHS::SmartComponent(ini.component.name, argc, argv);

		std::cout << "Component SmartPTUServer is named " << ini.component.name
				<< "." << std::endl;

		// create ports
		baseStateClient = new CHS::PushTimedClient<
				CommBasicObjects::CommBaseState>(component);
		baseStateQueryClient = new CHS::QueryClient<CommBasicObjects::CommVoid,
				CommBasicObjects::CommBaseState>(component);
		devicePoseStateServer = new CHS::PushNewestServer<
				CommBasicObjects::CommDevicePoseState>(component,
				ini.devicePoseStateServer.serviceName);
		threadMoveQueryHandler = new CHS::ThreadQueueQueryHandler<
				CommPTUObjects::CommPTUMoveRequest,
				CommPTUObjects::CommPTUMoveResponse>(moveQueryHandler);
		moveQueryServer = new CHS::QueryServer<
				CommPTUObjects::CommPTUMoveRequest,
				CommPTUObjects::CommPTUMoveResponse>(component,
				ini.moveQueryServer.serviceName, *threadMoveQueryHandler);

		paramServer = new CHS::SendServer<CommPTUObjects::CommPTUParameter>(
				component, ini.paramServer.serviceName, paramHandler);

		stateServer = new CHS::SmartStateServer(component,
				ini.stateServer.serviceName, stateChangeHandler);
		// define states for stateServer (CHS::SmartStateServer) 
		if (stateServer->defineStates("active", "active") != CHS::SMART_OK)
			std::cerr << "ERROR: define state" << std::endl;

	} catch (const CORBA::Exception &)
	{
		std::cerr << "Uncaught CORBA exception" << std::endl;
	} catch (...)
	{
		std::cerr << "Uncaught exception" << std::endl;
	}
}

// run the component
void SmartPTUServer::run()
{
	compHandler.onStartup();
	component->run();
	delete component;
}

void SmartPTUServer::loadParameter(int argc, char *argv[])
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
			std::cout << "load SmartPTUServer.ini parameter file\n";
			parameter.addFile("SmartPTUServer.ini");
		}

		// than add command line arguments to allow overwriting of parameters
		// from file
		parameter.addCommandLine("", argc, argv);

		// print all known parameters
		parameter.print(); // TODO remove this


		// load parameter
		parameter.getString("component", "name", ini.component.name);

		parameter.getString("devicePoseStateServer", "serviceName",
				ini.devicePoseStateServer.serviceName);
		parameter.getString("moveQueryServer", "serviceName",
				ini.moveQueryServer.serviceName);
		parameter.getString("paramServer", "serviceName",
				ini.paramServer.serviceName);
		parameter.getString("stateServer", "serviceName",
				ini.stateServer.serviceName);
		parameter.getString("baseStateClient", "serverName",
				ini.baseStateClient.serverName);
		parameter.getString("baseStateClient", "serviceName",
				ini.baseStateClient.serviceName);
		parameter.getInt("baseStateClient", "interval",
				ini.baseStateClient.interval);
		parameter.getString("baseStateQueryClient", "serverName",
				ini.baseStateQueryClient.serverName);
		parameter.getString("baseStateQueryClient", "serviceName",
				ini.baseStateQueryClient.serviceName);
		parameter.getDouble("PTU", "azimuth", ini.PTU.azimuth);
		parameter.getString("PTU", "device", ini.PTU.device);
		parameter.getDouble("PTU", "elevation", ini.PTU.elevation);
		parameter.getDouble("PTU", "roll", ini.PTU.roll);
		parameter.getTruthValue("PTU", "verbose", ini.PTU.verbose);
		parameter.getInt("PTU", "x", ini.PTU.x);
		parameter.getInt("PTU", "y", ini.PTU.y);
		parameter.getInt("PTU", "z", ini.PTU.z);
		parameter.getDouble("base", "base_a", ini.base.base_a);
		parameter.getTruthValue("base", "on_base", ini.base.on_base);
		parameter.getDouble("base", "steer_a", ini.base.steer_a);
		parameter.getDouble("base", "turret_a", ini.base.turret_a);
		parameter.getInt("base", "x", ini.base.x);
		parameter.getInt("base", "y", ini.base.y);
		parameter.getInt("base", "z", ini.base.z);
		parameter.getDouble("hardware", "acceleration_pan",
				ini.hardware.acceleration_pan);
		parameter.getDouble("hardware", "acceleration_tilt",
				ini.hardware.acceleration_tilt);
		parameter.getDouble("hardware", "max_speed_pan",
				ini.hardware.max_speed_pan);
		parameter.getDouble("hardware", "max_speed_tilt",
				ini.hardware.max_speed_tilt);
		parameter.getDouble("hardware", "min_speed_pan",
				ini.hardware.min_speed_pan);
		parameter.getDouble("hardware", "min_speed_tilt",
				ini.hardware.min_speed_tilt);
		parameter.getDouble("hardware", "speed_pan", ini.hardware.speed_pan);
		parameter.getDouble("hardware", "speed_tilt", ini.hardware.speed_tilt);
		parameter.getDouble("hardware", "start_up_speed_pan",
				ini.hardware.start_up_speed_pan);
		parameter.getDouble("hardware", "start_up_speed_tilt",
				ini.hardware.start_up_speed_tilt);

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

