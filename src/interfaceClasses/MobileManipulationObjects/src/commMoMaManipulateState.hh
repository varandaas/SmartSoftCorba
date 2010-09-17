//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.2.1
// The SmartSoft Toolchain has been developed by:
//
// ZAFH Servicerobotic Ulm
// Christian Schlegel (schlegel@hs-ulm.de)
// University of Applied Sciences
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// http://smart-robotics.sourceforge.net/
//
// This file is generated once. Modify this file to your needs.
// If you want the workflow to re-generate this file, please
// delete it before running the workflow.
//
//------------------------------------------------------------------------
//
//  Copyright (C) 2009 Manuel Wopfner
//
//        wopfner@hs-ulm.de
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
//--------------------------------------------------------------------------
#ifndef _COMM_MOMAMANIPULATESTATE_HH
#define _COMM_MOMAMANIPULATESTATE_HH

#include <string>

// include client-side file generated by IDL compiler
#include "gen/smartMoMaManipulateStateC.hh"

namespace Smart
{

class CommMoMaManipulateState
{
protected:
	SmartIDL::MoMaManipulateState moMaManipulateState;

public:
	CommMoMaManipulateState()
	{
	}
	virtual ~CommMoMaManipulateState()
	{
	}

	void get(CORBA::Any &a) const;
	void set(const CORBA::Any &a);
	static inline std::string identifier(void)
	{
		return "Smart::MoMaManipulateState";
	}

	//
	// user interfaces

	void setSize(uint32_t size);
	uint32_t getSize() const;

	void setState(uint32_t index, const std::string& value);
	void getState(uint32_t index, std::string& value) const;

	void setObjectId(uint32_t index, uint32_t objectId);
	uint32_t getObjectId(uint32_t index) const;


};

}
#endif
