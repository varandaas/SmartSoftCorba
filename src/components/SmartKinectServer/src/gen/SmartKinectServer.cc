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

#include "SmartKinectServer.hh"

// constructor
SmartKinectServer::SmartKinectServer() :
	ImageTaskCondMutex(ImageTaskMutex)
{
	std::cout << "constructor of SmartKinectServer\n";

	ini.component.name = "SmartKinectServer";

	ini.imagePushNewestServer.serviceName = "imageNewest";
	ini.imageQueryServer.serviceName = "imageQuery";
	ini.stateServer.serviceName = "state";
	ini.basePushTimedClient.serverName = "SmartPioneerBaseServer";
	ini.basePushTimedClient.serviceName = "basestate";
	ini.basePushTimedClient.interval = 1;
	ini.base.base_a = 0;
	ini.base.on_base = true;
	ini.base.steer_a = 0;
	ini.base.turret_a = 0;
	ini.base.x = 0;
	ini.base.y = 0;
	ini.base.z = 0;
	ini.component.debug_info = false;
	ini.component.push_newest_active = true;
	ini.component.valid_image_time = 1.0;
	ini.hardware_properties.height = 480;
	ini.hardware_properties.max_distance = 8000;
	ini.hardware_properties.min_distance = 700;
	ini.hardware_properties.width = 640;
	ini.sensor_pose.azimuth = 0;
	ini.sensor_pose.elevation = 0;
	ini.sensor_pose.roll = 0;
	ini.sensor_pose.x = 0;
	ini.sensor_pose.y = 0;
	ini.sensor_pose.z = 0;
}

void SmartKinectServer::init(int argc, char *argv[])
{
	try
	{
		loadParameter(argc, argv);
		component = new CHS::SmartComponent(ini.component.name, argc, argv);

		std::cout << "Component SmartKinectServer is named "
				<< ini.component.name << "." << std::endl;

		// create ports
		basePushTimedClient = new CHS::PushTimedClient<
				CommBasicObjects::CommBaseState>(component);
		imagePushNewestServer = new CHS::PushNewestServer<
				CommVisionObjects::CommKinectImage>(component,
				ini.imagePushNewestServer.serviceName);
		imageQueryServer = new CHS::QueryServer<CommBasicObjects::CommVoid,
				CommVisionObjects::CommKinectImage>(component,
				ini.imageQueryServer.serviceName, imageQueryHandler);

		stateServer = new CHS::SmartStateServer(component,
				ini.stateServer.serviceName, stateChangeHandler);
		// define states for stateServer (CHS::SmartStateServer) 
		if (stateServer->defineStates("active", "active") != CHS::SMART_OK)
			std::cerr << "ERROR: define state" << std::endl;

		// create timer
		double fractpart, intpart;
		// setup imageTaskTimer
		fractpart = modf(0.04, &intpart);
		component->getTimerThread().scheduleTimer(imageTaskTimer, (void*) 0,
				ACE_Time_Value(0, 0), ACE_Time_Value(intpart, (int) (fractpart
						* 1000* 1000 )));

	}
	catch (const CORBA::Exception &)
	{
		std::cerr << "Uncaught CORBA exception" << std::endl;
	}
	catch (...)
	{
		std::cerr << "Uncaught exception" << std::endl;
	}
}

// run the component
void SmartKinectServer::run()
{
	compHandler.onStartup();
	component->run();
	delete component;
}

void SmartKinectServer::loadParameter(int argc, char *argv[])
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
			std::cout << "load SmartKinectServer.ini parameter file\n";
			parameter.addFile("SmartKinectServer.ini");
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
		parameter.getString("imageQueryServer", "serviceName",
				ini.imageQueryServer.serviceName);
		parameter.getString("stateServer", "serviceName",
				ini.stateServer.serviceName);
		parameter.getString("basePushTimedClient", "serverName",
				ini.basePushTimedClient.serverName);
		parameter.getString("basePushTimedClient", "serviceName",
				ini.basePushTimedClient.serviceName);
		parameter.getInt("basePushTimedClient", "interval",
				ini.basePushTimedClient.interval);
		parameter.getDouble("base", "base_a", ini.base.base_a);
		parameter.getTruthValue("base", "on_base", ini.base.on_base);
		parameter.getDouble("base", "steer_a", ini.base.steer_a);
		parameter.getDouble("base", "turret_a", ini.base.turret_a);
		parameter.getInt("base", "x", ini.base.x);
		parameter.getInt("base", "y", ini.base.y);
		parameter.getInt("base", "z", ini.base.z);
		parameter.getTruthValue("component", "debug_info",
				ini.component.debug_info);
		parameter.getTruthValue("component", "push_newest_active",
				ini.component.push_newest_active);
		parameter.getDouble("component", "valid_image_time",
				ini.component.valid_image_time);
		parameter.getInt("hardware_properties", "height",
				ini.hardware_properties.height);
		parameter.getDouble("hardware_properties", "max_distance",
				ini.hardware_properties.max_distance);
		parameter.getDouble("hardware_properties", "min_distance",
				ini.hardware_properties.min_distance);
		parameter.getInt("hardware_properties", "width",
				ini.hardware_properties.width);
		parameter.getDouble("sensor_pose", "azimuth", ini.sensor_pose.azimuth);
		parameter.getDouble("sensor_pose", "elevation",
				ini.sensor_pose.elevation);
		parameter.getDouble("sensor_pose", "roll", ini.sensor_pose.roll);
		parameter.getDouble("sensor_pose", "x", ini.sensor_pose.x);
		parameter.getDouble("sensor_pose", "y", ini.sensor_pose.y);
		parameter.getDouble("sensor_pose", "z", ini.sensor_pose.z);

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

