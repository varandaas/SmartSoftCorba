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

#ifndef _SMARTROBOTCONSOLE_HH
#define _SMARTROBOTCONSOLE_HH

#include <iostream>
#include "smartSoft.hh"
#include "../SmartRobotConsoleCore.hh"
// include communication objects
#include <CommBasicObjects/commBaseParameter.hh>
#include <CommForkliftObjects/commForkliftParameter.hh>
#include <CommManipulatorObjects/commGripperParam.hh>
#include <CommNavigationObjects/commAmclParameter.hh>
#include <CommNavigationObjects/commCdlGoalEventParameter.hh>
#include <CommNavigationObjects/commCdlGoalEventResult.hh>
#include <CommNavigationObjects/commCdlParameter.hh>
#include <CommNavigationObjects/commGMappingParameter.hh>
#include <CommNavigationObjects/commMapperParameter.hh>
#include <CommNavigationObjects/commPlannerEventParameter.hh>
#include <CommNavigationObjects/commPlannerEventResult.hh>
#include <CommNavigationObjects/commPlannerParameter.hh>
#include <CommPTUObjects/commPTUMoveRequest.hh>
#include <CommPTUObjects/commPTUMoveResponse.hh>
#include <CommPersonDetectionObjects/commPersonDetectionParameter.hh>
#include <CommSpeechObjects/commSpeechInputParameter.hh>
#include <CommSpeechObjects/commSpeechOutputMessage.hh>
#include <CommTrackingObjects/commFollowMeParameter.hh>
// include tasks	

#include "../ConsoleTask.hh"
#include "../GoalEventTask.hh"
#include "../PlannerNoPathEventTask.hh"
// include handler
#include "../CompHandler.hh"

#define COMP SmartRobotConsole::instance()

class SmartRobotConsole: public SmartRobotConsoleCore
{
private:
	static SmartRobotConsole _smartRobotConsole;

	// constructor
	SmartRobotConsole();

	// copy-constructor
	SmartRobotConsole(const SmartRobotConsole& cc);

	// destructor
	~SmartRobotConsole()
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
	CHS::SmartMutex SpeechLock;

	// create condition mutex


	// instantiate tasks

	ConsoleTask consoleTask;
	GoalEventTask goalEventTask;
	PlannerNoPathEventTask plannerNoPathEventTask;

	// ports
	CHS::SendClient<CommNavigationObjects::CommAmclParameter>
			*amclParameterClient;
	CHS::SmartStateClient *amclStateClient;
	CHS::SendClient<CommBasicObjects::CommBaseParameter> *baseParameterClient;
	CHS::EventClient<CommNavigationObjects::CommCdlGoalEventParameter,
			CommNavigationObjects::CommCdlGoalEventResult> *cdlGoalEventClient;
	CHS::SendClient<CommNavigationObjects::CommCdlParameter>
			*cdlParameterClient;
	CHS::SmartStateClient *cdlStateClient;
	CHS::SendClient<CommTrackingObjects::CommFollowMeParameter>
			*followMeParameterClient;
	CHS::SendClient<CommForkliftObjects::CommForkliftParameter>
			*forkliftParameterClient;
	CHS::SendClient<CommNavigationObjects::CommGMappingParameter>
			*gmappingParameterClient;
	CHS::SendClient<CommNavigationObjects::CommMapperParameter>
			*mapperParameterClient;
	CHS::SmartStateClient *mapperStateClient;
	CHS::SendClient<CommPersonDetectionObjects::CommPersonDetectionParameter>
			*personDetectionParameterClient;
	CHS::EventClient<CommNavigationObjects::CommPlannerEventParameter,
			CommNavigationObjects::CommPlannerEventResult> *plannerEventClient;
	CHS::SendClient<CommNavigationObjects::CommPlannerParameter>
			*plannerParameterClient;
	CHS::SmartStateClient *plannerStateClient;
	CHS::QueryClient<CommPTUObjects::CommPTUMoveRequest,
			CommPTUObjects::CommPTUMoveResponse> *ptuQueryClient;
	CHS::SmartStateClient *ptuStateClient;
	CHS::SendClient<CommManipulatorObjects::CommGripperParam>
			*schunkGripperParameterClient;
	CHS::SendClient<CommSpeechObjects::CommSpeechInputParameter>
			*speechParameterClient;
	CHS::SendClient<CommSpeechObjects::CommSpeechOutputMessage>
			*speechSendClient;
	CHS::SmartStateClient *speechStateClient;
	CHS::WiringSlave *wiringSlave;

	void init(int argc, char *argv[]);
	void run();

	// return singleton instance
	static SmartRobotConsole* instance()
	{
		return (SmartRobotConsole*) &_smartRobotConsole;
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

		struct ini_amclParameterClient
		{
			std::string serverName;
			std::string serviceName;
		} amclParameterClient;

		struct ini_amclStateClient
		{
			std::string serverName;
			std::string serviceName;
		} amclStateClient;

		struct ini_baseParameterClient
		{
			std::string serverName;
			std::string serviceName;
		} baseParameterClient;

		struct ini_cdlGoalEventClient
		{
			std::string serverName;
			std::string serviceName;
		} cdlGoalEventClient;

		struct ini_cdlParameterClient
		{
			std::string serverName;
			std::string serviceName;
		} cdlParameterClient;

		struct ini_cdlStateClient
		{
			std::string serverName;
			std::string serviceName;
		} cdlStateClient;

		struct ini_followMeParameterClient
		{
			std::string serverName;
			std::string serviceName;
		} followMeParameterClient;

		struct ini_forkliftParameterClient
		{
			std::string serverName;
			std::string serviceName;
		} forkliftParameterClient;

		struct ini_gmappingParameterClient
		{
			std::string serverName;
			std::string serviceName;
		} gmappingParameterClient;

		struct ini_mapperParameterClient
		{
			std::string serverName;
			std::string serviceName;
		} mapperParameterClient;

		struct ini_mapperStateClient
		{
			std::string serverName;
			std::string serviceName;
		} mapperStateClient;

		struct ini_personDetectionParameterClient
		{
			std::string serverName;
			std::string serviceName;
		} personDetectionParameterClient;

		struct ini_plannerEventClient
		{
			std::string serverName;
			std::string serviceName;
		} plannerEventClient;

		struct ini_plannerParameterClient
		{
			std::string serverName;
			std::string serviceName;
		} plannerParameterClient;

		struct ini_plannerStateClient
		{
			std::string serverName;
			std::string serviceName;
		} plannerStateClient;

		struct ini_ptuQueryClient
		{
			std::string serverName;
			std::string serviceName;
		} ptuQueryClient;

		struct ini_ptuStateClient
		{
			std::string serverName;
			std::string serviceName;
		} ptuStateClient;

		struct ini_schunkGripperParameterClient
		{
			std::string serverName;
			std::string serviceName;
		} schunkGripperParameterClient;

		struct ini_speechParameterClient
		{
			std::string serverName;
			std::string serviceName;
		} speechParameterClient;

		struct ini_speechSendClient
		{
			std::string serverName;
			std::string serviceName;
		} speechSendClient;

		struct ini_speechStateClient
		{
			std::string serverName;
			std::string serviceName;
		} speechStateClient;

	} ini;

};
#endif
