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

#ifndef _COMMFORKLIFTOBJECTS_ENUM_HH_FORKLIFTTAGTYPE
#define _COMMFORKLIFTOBJECTS_ENUM_HH_FORKLIFTTAGTYPE

#include <CommForkliftObjects/gen/enumForkliftTagTypeC.hh>
#include <string>
#include <ostream>

namespace CommForkliftObjects
{

class ForkliftTagType
{
public:
	enum literal
	{

		MOVE_ABS_MM = CommForkliftObjectsIDL::LITERAL_MOVE_ABS_MM
	};

	ForkliftTagType()
	{
	}

	ForkliftTagType(literal t)
	{
		value = t;
	}

	operator literal()
	{
		return value;
	}

	ForkliftTagType(CommForkliftObjectsIDL::ENUM_ForkliftTagType t)
	{
		value = (literal) t;
	}

	bool operator ==(ForkliftTagType& t)
	{
		return this->value == t.value;
	}

	CommForkliftObjectsIDL::ENUM_ForkliftTagType get_value_idl()
	{
		return (CommForkliftObjectsIDL::ENUM_ForkliftTagType) value;
	}

	literal get_value() const
	{
		return value;
	}

	std::string get_string() const
	{
		switch (value)
		{

		case MOVE_ABS_MM:
			return "ForkliftTagType::MOVE_ABS_MM";
			break;

		default:
			return "UNKNOWN!";
			break;
		}
	}

private:
	literal value;
};

inline std::ostream &operator<<(std::ostream &os, const ForkliftTagType &e)
{
	os << e.get_string();
	return os;
}

}
#endif
