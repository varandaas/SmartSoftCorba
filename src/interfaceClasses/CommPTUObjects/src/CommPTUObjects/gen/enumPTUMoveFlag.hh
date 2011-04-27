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

#ifndef _COMMPTUOBJECTS_ENUM_HH_PTUMOVEFLAG
#define _COMMPTUOBJECTS_ENUM_HH_PTUMOVEFLAG

#include <CommPTUObjects/gen/enumPTUMoveFlagC.hh>
#include <string>
#include <ostream>

namespace CommPTUObjects
{

class PTUMoveFlag
{
public:
	enum literal
	{

		PAN_ABSOLUTE = CommPTUObjectsIDL::LITERAL_PAN_ABSOLUTE,

		PAN_RELATIVE = CommPTUObjectsIDL::LITERAL_PAN_RELATIVE,

		PAN_TILT_ABSOLUTE = CommPTUObjectsIDL::LITERAL_PAN_TILT_ABSOLUTE,

		PAN_TILT_RELATIVE = CommPTUObjectsIDL::LITERAL_PAN_TILT_RELATIVE,

		POSITION_ROBOT = CommPTUObjectsIDL::LITERAL_POSITION_ROBOT,

		POSITION_WORLD = CommPTUObjectsIDL::LITERAL_POSITION_WORLD,

		TILT_ABSOLUTE = CommPTUObjectsIDL::LITERAL_TILT_ABSOLUTE,

		TILT_RELATIVE = CommPTUObjectsIDL::LITERAL_TILT_RELATIVE
	};

	PTUMoveFlag()
	{
	}

	PTUMoveFlag(literal t)
	{
		value = t;
	}

	operator literal()
	{
		return value;
	}

	PTUMoveFlag(CommPTUObjectsIDL::ENUM_PTUMoveFlag t)
	{
		value = (literal) t;
	}

	bool operator ==(PTUMoveFlag& t)
	{
		return this->value == t.value;
	}

	CommPTUObjectsIDL::ENUM_PTUMoveFlag get_value_idl()
	{
		return (CommPTUObjectsIDL::ENUM_PTUMoveFlag) value;
	}

	literal get_value() const
	{
		return value;
	}

	std::string get_string() const
	{
		switch (value)
		{

		case PAN_ABSOLUTE:
			return "PTUMoveFlag::PAN_ABSOLUTE";
			break;

		case PAN_RELATIVE:
			return "PTUMoveFlag::PAN_RELATIVE";
			break;

		case PAN_TILT_ABSOLUTE:
			return "PTUMoveFlag::PAN_TILT_ABSOLUTE";
			break;

		case PAN_TILT_RELATIVE:
			return "PTUMoveFlag::PAN_TILT_RELATIVE";
			break;

		case POSITION_ROBOT:
			return "PTUMoveFlag::POSITION_ROBOT";
			break;

		case POSITION_WORLD:
			return "PTUMoveFlag::POSITION_WORLD";
			break;

		case TILT_ABSOLUTE:
			return "PTUMoveFlag::TILT_ABSOLUTE";
			break;

		case TILT_RELATIVE:
			return "PTUMoveFlag::TILT_RELATIVE";
			break;

		default:
			return "UNKNOWN!";
			break;
		}
	}

private:
	literal value;
};

inline std::ostream &operator<<(std::ostream &os, const PTUMoveFlag &e)
{
	os << e.get_string();
	return os;
}

}
#endif
