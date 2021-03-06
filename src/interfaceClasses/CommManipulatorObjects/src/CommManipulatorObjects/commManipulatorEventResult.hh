//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.6.0
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
// If you want the workflow to re-generate this file, please
// delete it before running the workflow.
//------------------------------------------------------------------------
//
//  Copyright (C) 2010 Manuel Wopfner
//
//        wopfner@hs-ulm.de
//
//        Christian Schlegel (schlegel@hs-ulm.de)
//        University of Applied Sciences
//        Prittwitzstr. 10
//        89075 Ulm (Germany)
//
//  This file is part of the "CommManipulatorObjects".
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

#ifndef _COMM_COMMMANIPULATOREVENTRESULT_HH
#define _COMM_COMMMANIPULATOREVENTRESULT_HH

#include <string>

// include header-files of includes communication objects
#include <CommManipulatorObjects/gen/enumManipulatorEvent.hh>

// include client-side file generated by IDL compiler
#include "CommManipulatorObjects/gen/smartCommManipulatorEventResultC.hh"

namespace CommManipulatorObjects {

class CommManipulatorEventResult {
protected:
	CommManipulatorObjectsIDL::CommManipulatorEventResult idl_CommManipulatorEventResult;

public:

	CommManipulatorEventResult() {
	}

	CommManipulatorEventResult(const CommManipulatorObjectsIDL::CommManipulatorEventResult &obj) :
		idl_CommManipulatorEventResult(obj) {
	}

	operator CommManipulatorObjectsIDL::CommManipulatorEventResult() const
	{
		return idl_CommManipulatorEventResult;
	}

	virtual ~CommManipulatorEventResult() {
	}

	void get(CORBA::Any &a) const;
	void set(const CORBA::Any &a);


	static inline std::string identifier(void) {
		return "CommManipulatorObjects::CommManipulatorEventResult";
	}

	//
	// user interfaces

	/**
	 * Set the event that occurred.
	 */
	inline void set_event(CommManipulatorObjects::ManipulatorEvent event) {
		idl_CommManipulatorEventResult.event = event.get_value_idl();
	}

	/**
	 * Get the event that occurred.
	 */
	inline CommManipulatorObjects::ManipulatorEvent get_event() const {
		return idl_CommManipulatorEventResult.event;
	}

	/**
	 * Get the event as string that occurred.
	 */
	void get(char* r) const;

};

}
#endif
