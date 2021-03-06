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
// This file is generated once. Modify this file to your needs.
// If you want the toolchain to re-generate this file, please
// delete it before running the code generator.
//--------------------------------------------------------------------------
// --------------------------------------------------------------------------
//
//  Copyright (C) 2011 Andreas Steck, Alex Lotz
//
//        schlegel@hs-ulm.de
//
//        ZAFH Servicerobotik Ulm
//        University of Applied Sciences
//        Prittwitzstr. 10
//        D-89075 Ulm
//        Germany
//
//  This file is part of the "SmartSoft Communication Classes".
//  It provides basic standardized data types for communication between
//  different components in the mobile robotics context. These classes
//  are designed to be used in conjunction with the SmartSoft Communication
//  Library.
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// --------------------------------------------------------------------------

#ifndef _COMM_COMMBASICOBJECTS_COMMBATTERYEVENT_HH
#define _COMM_COMMBASICOBJECTS_COMMBATTERYEVENT_HH

#include <string>

// include files of classes

// include header-files of included communication objects

// include enums
#include <CommBasicObjects/gen/enumComparisonState.hh>

// include client-side file generated by IDL compiler
#include "CommBasicObjects/gen/smartCommBatteryEventC.hh"

namespace CommBasicObjects
{

class CommBatteryEvent
{
protected:
	CommBasicObjectsIDL::CommBatteryEvent idl_CommBatteryEvent;

public:
	CommBatteryEvent()
	{
	}

	CommBatteryEvent(const CommBasicObjectsIDL::CommBatteryEvent &obj) :
		idl_CommBatteryEvent(obj)
	{
	}

	virtual ~CommBatteryEvent()
	{
	}

	operator CommBasicObjectsIDL::CommBatteryEvent() const
	{
		return idl_CommBatteryEvent;
	}

	void get(CORBA::Any &a) const;
	void set(const CORBA::Any &a);

	static inline std::string identifier(void)
	{
		return "CommBasicObjects::CommBatteryEvent";
	}

	//
	// user interfaces
	inline void setVoltage(const double &value) { idl_CommBatteryEvent.chargeValue = value; }
	inline double getVoltage() const { return idl_CommBatteryEvent.chargeValue; }

	inline void setBatteryState(ComparisonState state) { idl_CommBatteryEvent.state = state.get_value_idl(); }
	inline ComparisonState getBatteryState() const { return idl_CommBatteryEvent.state; }
};

}
#endif
