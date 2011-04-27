//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.8.0
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

#ifndef _SAMPLEPARAMETERCOMP_HH
#define _SAMPLEPARAMETERCOMP_HH

#include <iostream>
#include "smartSoft.hh"
#include "../SampleParameterCompCore.hh"
// include communication objects
#include <CommSampleObjects/commSampleValues.hh>

// include tasks	

// include handler
#include "../CompHandler.hh"

#define COMP SampleParameterComp::instance()

class SampleParameterComp: public SampleParameterCompCore
{
private:
	static SampleParameterComp _sampleParameterComp;

	// constructor
	SampleParameterComp();

	// copy-constructor
	SampleParameterComp(const SampleParameterComp& cc);

	// destructor
	~SampleParameterComp()
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


	// ports
	CHS::PushNewestServer<CommSampleObjects::CommSampleValues> *samplePort;

	void init(int argc, char *argv[]);
	void run();

	// return singleton instance
	static SampleParameterComp* instance()
	{
		return (SampleParameterComp*) &_sampleParameterComp;
	}

	// ini parameter
	struct ini_ini
	{

		struct ini_samplePort
		{
			std::string serviceName;
		} samplePort;

		struct ini_general
		{

			bool verbose;
		} general;

		struct ini_laser
		{

			unsigned long baudrate;

			std::string type;
		} laser;

		struct ini_robot
		{

			std::string device;

			unsigned short maxSpeed;

			std::string name;
		} robot;
	} ini;

};
#endif