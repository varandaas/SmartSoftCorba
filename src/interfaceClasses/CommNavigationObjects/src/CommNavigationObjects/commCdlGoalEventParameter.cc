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

// --------------------------------------------------------------------------
//
//  Copyright (C) 2008 Christian Schlegel, Andreas Steck, Matthias Lutz
//
//        schlegel@hs-ulm.de
//        steck@hs-ulm.de
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

#include "commCdlGoalEventParameter.hh"

using namespace CommNavigationObjects;

void CommCdlGoalEventParameter::get(CORBA::Any &a) const
{
	a <<= idl_CommCdlGoalEventParameter;
}

void CommCdlGoalEventParameter::set(const CORBA::Any &a)
{
	CommNavigationObjectsIDL::CommCdlGoalEventParameter *tmp_cmd;
	if (a >>= tmp_cmd)
	{
		idl_CommCdlGoalEventParameter = *tmp_cmd;
	}
}

void CommCdlGoalEventParameter::set(CdlGoalEventType r)
{
	idl_CommCdlGoalEventParameter.oldState = r.get_value_idl();
}

void CommCdlGoalEventParameter::get(CdlGoalEventType& r) const
{
  r = idl_CommCdlGoalEventParameter.oldState;
}

void CommCdlGoalEventParameter::print(std::ostream &os) const
{
  os << "Parameter : " << idl_CommCdlGoalEventParameter.oldState << std::endl;
}
