//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.10.3
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

#ifndef _COMMNAVIGATIONOBJECTS_ENUM_HH_PLANNERTAGTYPE
#define _COMMNAVIGATIONOBJECTS_ENUM_HH_PLANNERTAGTYPE

#include <CommNavigationObjects/gen/enumPlannerTagTypeC.hh>
#include <string>
#include <ostream>

namespace CommNavigationObjects
{

class PlannerTagType
{
public:
	enum literal
	{

		PLANNER_DELETE_GOAL = CommNavigationObjectsIDL::LITERAL_PLANNER_DELETE_GOAL,

		PLANNER_ID = CommNavigationObjectsIDL::LITERAL_PLANNER_ID,

		PLANNER_SET_DESTINATION_CIRCLE = CommNavigationObjectsIDL::LITERAL_PLANNER_SET_DESTINATION_CIRCLE,

		PLANNER_SET_DESTINATION_LINE = CommNavigationObjectsIDL::LITERAL_PLANNER_SET_DESTINATION_LINE
	};

	PlannerTagType()
	{
	}

	PlannerTagType(literal t)
	{
		value = t;
	}

	operator literal()
	{
		return value;
	}

	PlannerTagType(CommNavigationObjectsIDL::ENUM_PlannerTagType t)
	{
		value = (literal) t;
	}

	bool operator ==(PlannerTagType& t)
	{
		return this->value == t.value;
	}

	CommNavigationObjectsIDL::ENUM_PlannerTagType get_value_idl()
	{
		return (CommNavigationObjectsIDL::ENUM_PlannerTagType) value;
	}

	literal get_value() const
	{
		return value;
	}

	std::string get_string() const
	{
		switch (value)
		{

		case PLANNER_DELETE_GOAL:
			return "PlannerTagType::PLANNER_DELETE_GOAL";
			break;

		case PLANNER_ID:
			return "PlannerTagType::PLANNER_ID";
			break;

		case PLANNER_SET_DESTINATION_CIRCLE:
			return "PlannerTagType::PLANNER_SET_DESTINATION_CIRCLE";
			break;

		case PLANNER_SET_DESTINATION_LINE:
			return "PlannerTagType::PLANNER_SET_DESTINATION_LINE";
			break;

		default:
			return "UNKNOWN!";
			break;
		}
	}

private:
	literal value;
};

inline std::ostream &operator<<(std::ostream &os, const PlannerTagType &e)
{
	os << e.get_string();
	return os;
}

}
#endif
