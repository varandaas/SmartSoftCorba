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

#ifndef _COMMVISIONOBJECTS_ENUM_HH_TOFPARAMETER
#define _COMMVISIONOBJECTS_ENUM_HH_TOFPARAMETER

#include <CommVisionObjects/gen/enumToFParameterC.hh>
#include <string>
#include <ostream>

namespace CommVisionObjects
{

class ToFParameter
{
public:
	enum literal
	{

		INTEGRATION_TIME = CommVisionObjectsIDL::LITERAL_INTEGRATION_TIME,

		MODULATION_FREQUENCY = CommVisionObjectsIDL::LITERAL_MODULATION_FREQUENCY,

		UNKNOWN = CommVisionObjectsIDL::LITERAL_UNKNOWN
	};

	ToFParameter()
	{
	}

	ToFParameter(literal t)
	{
		value = t;
	}

	operator literal()
	{
		return value;
	}

	ToFParameter(CommVisionObjectsIDL::ENUM_ToFParameter t)
	{
		value = (literal) t;
	}

	bool operator ==(ToFParameter& t)
	{
		return this->value == t.value;
	}

	CommVisionObjectsIDL::ENUM_ToFParameter get_value_idl()
	{
		return (CommVisionObjectsIDL::ENUM_ToFParameter) value;
	}

	literal get_value() const
	{
		return value;
	}

	std::string get_string() const
	{
		switch (value)
		{

		case INTEGRATION_TIME:
			return "ToFParameter::INTEGRATION_TIME";
			break;

		case MODULATION_FREQUENCY:
			return "ToFParameter::MODULATION_FREQUENCY";
			break;

		case UNKNOWN:
			return "ToFParameter::UNKNOWN";
			break;

		default:
			return "UNKNOWN!";
			break;
		}
	}

private:
	literal value;
};

inline std::ostream &operator<<(std::ostream &os, const ToFParameter &e)
{
	os << e.get_string();
	return os;
}

}
#endif