//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.10.0
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
// This file is generated once. Modify this file to your needs.
// If you want the toolchain to re-generate this file, please
// delete it before running the code generator.
//--------------------------------------------------------------------------

#include "commPlannerEventParameter.hh"

using namespace CommNavigationObjects;

void CommPlannerEventParameter::get(CORBA::Any &a) const
{
	a <<= idl_CommPlannerEventParameter;
}

void CommPlannerEventParameter::set(const CORBA::Any &a)
{
	CommNavigationObjectsIDL::CommPlannerEventParameter *tmp_cmd;
	if (a >>= tmp_cmd)
	{
		idl_CommPlannerEventParameter = *tmp_cmd;
	}
}

void CommPlannerEventParameter::set(PlannerEventType r)
{
	idl_CommPlannerEventParameter.oldState = r.get_value_idl();
}

void CommPlannerEventParameter::get(PlannerEventType& r) const
{
	r = idl_CommPlannerEventParameter.oldState;
}

void CommPlannerEventParameter::print(std::ostream &os) const
{
	os << "Parameter : " << idl_CommPlannerEventParameter.oldState << std::endl;
}