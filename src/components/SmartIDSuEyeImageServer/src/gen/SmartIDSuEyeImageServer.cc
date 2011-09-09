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

#include "SmartIDSuEyeImageServer.hh"

// constructor
SmartIDSuEyeImageServer::SmartIDSuEyeImageServer()
{
	std::cout << "constructor of SmartIDSuEyeImageServer\n";

	ini.component.name = "SmartIDSuEyeImageServer";

	ini.imagePushNewestServer.serviceName = "imageNewest";
	ini.imagePushTimedServer.serviceName = "imageTimed";
	ini.imagePushTimedServer.cycle = 0.06;
	ini.imageQueryServer.serviceName = "imageQuery";
	ini.stateServer.serviceName = "state";
	ini.actuatorPushTimedClient.serverName = "SmartPTUServer";
	ini.actuatorPushTimedClient.serviceName = "devicePoseState";
	ini.basePushTimedClient.serverName = "SmartPlayerStageSimulator";
	ini.basePushTimedClient.serviceName = "baseState";
	ini.basePushTimedClient.interval = 1;
	ini.manipulatorPushTimedClient.serverName = "SmartKatanaServer";
	ini.manipulatorPushTimedClient.serviceName = "currentPose";
	ini.manipulatorPushTimedClient.interval = 1;
	ini.base.base_a = 0;
	ini.base.on_actuator = false;
	ini.base.on_base = true;
	ini.base.on_manipulator = false;
	ini.base.steer_a = 0;
	ini.base.turret_a = 0;
	ini.base.x = 0;
	ini.base.y = 0;
	ini.base.z = 0;
	ini.hardware.camera_id = 0;
	ini.hardware.parameter_file = "/cam/set1";
	ini.hardware_properties.distortionK1 = 0;
	ini.hardware_properties.distortionK2 = 0;
	ini.hardware_properties.distortionK3 = 0;
	ini.hardware_properties.distortionP1 = 0;
	ini.hardware_properties.distortionP2 = 0;
	ini.hardware_properties.intrinsicCx = 0;
	ini.hardware_properties.intrinsicCy = 0;
	ini.hardware_properties.intrinsicFx = 0;
	ini.hardware_properties.intrinsicFy = 0;
	ini.sensor_pose.azimuth = 0;
	ini.sensor_pose.elevation = 0;
	ini.sensor_pose.roll = 0;
	ini.sensor_pose.x = 0;
	ini.sensor_pose.y = 0;
	ini.sensor_pose.z = 0;
	ini.settings.debug_info = false;
	ini.settings.undistort_image = true;
}

void SmartIDSuEyeImageServer::init(int argc, char *argv[])
{
	try
	{
		loadParameter(argc, argv);
		component = new CHS::SmartComponent(ini.component.name, argc, argv);

		std::cout << "Component SmartIDSuEyeImageServer is named "
				<< ini.component.name << "." << std::endl;

		// create ports
		actuatorPushTimedClient = new CHS::PushNewestClient<
				CommBasicObjects::CommDevicePoseState>(component);
		basePushTimedClient = new CHS::PushTimedClient<
				CommBasicObjects::CommBaseState>(component);
		imagePushNewestServer = new CHS::PushNewestServer<
				CommVisionObjects::CommVideoImage>(component,
				ini.imagePushNewestServer.serviceName);
		imagePushTimedServer = new CHS::PushTimedServer<
				CommVisionObjects::CommVideoImage>(component,
				ini.imagePushTimedServer.serviceName, imagePushTimedHandler,
				ini.imagePushTimedServer.cycle);

		imageQueryServer = new CHS::QueryServer<CommBasicObjects::CommVoid,
				CommVisionObjects::CommVideoImage>(component,
				ini.imageQueryServer.serviceName, imageQueryHandler);

		manipulatorPushTimedClient = new CHS::PushTimedClient<
				CommManipulatorObjects::CommMobileManipulatorState>(component);
		stateServer = new CHS::SmartStateServer(component,
				ini.stateServer.serviceName, stateChangeHandler);
		// define states for stateServer (CHS::SmartStateServer) 
		if (stateServer->defineStates("pushimage", "queryonly")
				!= CHS::SMART_OK)
			std::cerr << "ERROR: define state" << std::endl;
		if (stateServer->defineStates("pushimage", "pushimage")
				!= CHS::SMART_OK)
			std::cerr << "ERROR: define state" << std::endl;
		if (stateServer->defineStates("queryonly", "queryonly")
				!= CHS::SMART_OK)
			std::cerr << "ERROR: define state" << std::endl;

		// add client port to wiring slave


	} catch (const CORBA::Exception &)
	{
		std::cerr << "Uncaught CORBA exception" << std::endl;
	} catch (...)
	{
		std::cerr << "Uncaught exception" << std::endl;
	}
}

// run the component
void SmartIDSuEyeImageServer::run()
{
	compHandler.onStartup();
	component->run();
	delete component;
}

void SmartIDSuEyeImageServer::loadParameter(int argc, char *argv[])
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
			std::cout << "load SmartIDSuEyeImageServer.ini parameter file\n";
			parameter.addFile("SmartIDSuEyeImageServer.ini");
		}

		// than add command line arguments to allow overwriting of parameters
		// from file
		parameter.addCommandLine("", argc, argv);

		// print all known parameters
		parameter.print(); // TODO remove this


		// load parameter
		parameter.getString("component", "name", ini.component.name);

		parameter.getString("imagePushNewestServer", "serviceName",
				ini.imagePushNewestServer.serviceName);
		parameter.getString("imagePushTimedServer", "serviceName",
				ini.imagePushTimedServer.serviceName);
		parameter.getDouble("imagePushTimedServer", "cycle",
				ini.imagePushTimedServer.cycle);
		parameter.getString("imageQueryServer", "serviceName",
				ini.imageQueryServer.serviceName);
		parameter.getString("stateServer", "serviceName",
				ini.stateServer.serviceName);
		parameter.getString("actuatorPushTimedClient", "serverName",
				ini.actuatorPushTimedClient.serverName);
		parameter.getString("actuatorPushTimedClient", "serviceName",
				ini.actuatorPushTimedClient.serviceName);
		parameter.getString("basePushTimedClient", "serverName",
				ini.basePushTimedClient.serverName);
		parameter.getString("basePushTimedClient", "serviceName",
				ini.basePushTimedClient.serviceName);
		parameter.getInt("basePushTimedClient", "interval",
				ini.basePushTimedClient.interval);
		parameter.getString("manipulatorPushTimedClient", "serverName",
				ini.manipulatorPushTimedClient.serverName);
		parameter.getString("manipulatorPushTimedClient", "serviceName",
				ini.manipulatorPushTimedClient.serviceName);
		parameter.getInt("manipulatorPushTimedClient", "interval",
				ini.manipulatorPushTimedClient.interval);
		parameter.getDouble("base", "base_a", ini.base.base_a);
		parameter.getTruthValue("base", "on_actuator", ini.base.on_actuator);
		parameter.getTruthValue("base", "on_base", ini.base.on_base);
		parameter.getTruthValue("base", "on_manipulator",
				ini.base.on_manipulator);
		parameter.getDouble("base", "steer_a", ini.base.steer_a);
		parameter.getDouble("base", "turret_a", ini.base.turret_a);
		parameter.getInt("base", "x", ini.base.x);
		parameter.getInt("base", "y", ini.base.y);
		parameter.getInt("base", "z", ini.base.z);
		parameter.getInt("hardware", "camera_id", ini.hardware.camera_id);
		parameter.getString("hardware", "parameter_file",
				ini.hardware.parameter_file);
		parameter.getDouble("hardware_properties", "distortionK1",
				ini.hardware_properties.distortionK1);
		parameter.getDouble("hardware_properties", "distortionK2",
				ini.hardware_properties.distortionK2);
		parameter.getDouble("hardware_properties", "distortionK3",
				ini.hardware_properties.distortionK3);
		parameter.getDouble("hardware_properties", "distortionP1",
				ini.hardware_properties.distortionP1);
		parameter.getDouble("hardware_properties", "distortionP2",
				ini.hardware_properties.distortionP2);
		parameter.getDouble("hardware_properties", "intrinsicCx",
				ini.hardware_properties.intrinsicCx);
		parameter.getDouble("hardware_properties", "intrinsicCy",
				ini.hardware_properties.intrinsicCy);
		parameter.getDouble("hardware_properties", "intrinsicFx",
				ini.hardware_properties.intrinsicFx);
		parameter.getDouble("hardware_properties", "intrinsicFy",
				ini.hardware_properties.intrinsicFy);
		parameter.getDouble("sensor_pose", "azimuth", ini.sensor_pose.azimuth);
		parameter.getDouble("sensor_pose", "elevation",
				ini.sensor_pose.elevation);
		parameter.getDouble("sensor_pose", "roll", ini.sensor_pose.roll);
		parameter.getInt("sensor_pose", "x", ini.sensor_pose.x);
		parameter.getInt("sensor_pose", "y", ini.sensor_pose.y);
		parameter.getInt("sensor_pose", "z", ini.sensor_pose.z);
		parameter.getTruthValue("settings", "debug_info",
				ini.settings.debug_info);
		parameter.getTruthValue("settings", "undistort_image",
				ini.settings.undistort_image);

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
