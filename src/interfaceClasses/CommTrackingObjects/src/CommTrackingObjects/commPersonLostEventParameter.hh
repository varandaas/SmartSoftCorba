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
// This file is generated once. Modify this file to your needs.
// If you want the toolchain to re-generate this file, please
// delete it before running the code generator.
//--------------------------------------------------------------------------

// --------------------------------------------------------------------------
//
//  Copyright (C) 2010 Andreas Steck, Matthias Lutz
//
//        schlegel@hs-ulm.de
//
//        Prof. Dr. Christian Schlegel
//        University of Applied Sciences
//        Prittwitzstr. 10
//        D-89075 Ulm
//        Germany
//
//  This file is part of the "SmartSoft Communication Library".
//  It provides standardized patterns for communication between
//  different components.
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
//
// --------------------------------------------------------------------------

#ifndef _COMM_COMMTRACKINGOBJECTS_COMMPERSONLOSTEVENTPARAMETER_HH
#define _COMM_COMMTRACKINGOBJECTS_COMMPERSONLOSTEVENTPARAMETER_HH

#include <string>
#include <iostream>

// include files of classes

// include header-files of included communication objects

// include enums
#include <CommTrackingObjects/gen/enumPersonLostEventType.hh>

// include client-side file generated by IDL compiler
#include "CommTrackingObjects/gen/smartCommPersonLostEventParameterC.hh"

namespace CommTrackingObjects
{

class CommPersonLostEventParameter
{
protected:
	CommTrackingObjectsIDL::CommPersonLostEventParameter
			idl_CommPersonLostEventParameter;

public:
	CommPersonLostEventParameter()
	{
	}

	CommPersonLostEventParameter(
			const CommTrackingObjectsIDL::CommPersonLostEventParameter &obj) :
		idl_CommPersonLostEventParameter(obj)
	{
	}

	virtual ~CommPersonLostEventParameter()
	{
	}

	operator CommTrackingObjectsIDL::CommPersonLostEventParameter() const
	{
		return idl_CommPersonLostEventParameter;
	}

	void get(CORBA::Any &a) const;
	void set(const CORBA::Any &a);

	static inline std::string identifier(void)
	{
		return "CommTrackingObjects::CommPersonLostEventParameter";
	}

	//
	// user interfaces
	void set(PersonLostEventType);
	void get(PersonLostEventType&) const;
	void print(std::ostream &os = std::cout) const;

};

inline std::ostream &operator<< (std::ostream &os, const CommPersonLostEventParameter &c) {
  c.print(os);
  return os;
};

}
#endif
