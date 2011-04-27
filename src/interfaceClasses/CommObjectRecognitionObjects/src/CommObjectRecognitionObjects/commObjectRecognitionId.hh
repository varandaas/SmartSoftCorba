//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.8.0
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
//  This file is part of the "CommObjectRecognitonObjects".
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

#ifndef _COMM_COMMOBJECTRECOGNITIONOBJECTS_COMMOBJECTRECOGNITIONID_HH
#define _COMM_COMMOBJECTRECOGNITIONOBJECTS_COMMOBJECTRECOGNITIONID_HH

#include <string>

// include files of classes
#include <iostream>
#include <string>

// include header-files of included communication objects

// include enums


// include client-side file generated by IDL compiler
#include "CommObjectRecognitionObjects/gen/smartCommObjectRecognitionIdC.hh"

#define LISP_SEPARATOR " ()\n"

namespace CommObjectRecognitionObjects
{

class CommObjectRecognitionId
{
protected:
	CommObjectRecognitionObjectsIDL::CommObjectRecognitionId
			idl_CommObjectRecognitionId;

public:
	CommObjectRecognitionId()
	{
	}

	CommObjectRecognitionId(
			const CommObjectRecognitionObjectsIDL::CommObjectRecognitionId &obj) :
		idl_CommObjectRecognitionId(obj)
	{
	}

	virtual ~CommObjectRecognitionId()
	{
	}

	void get(CORBA::Any &a) const;
	void set(const CORBA::Any &a);

	inline const CommObjectRecognitionObjectsIDL::CommObjectRecognitionId &get() const
	{
		return idl_CommObjectRecognitionId;
	}

	inline void set(
			const CommObjectRecognitionObjectsIDL::CommObjectRecognitionId &obj)
	{
		idl_CommObjectRecognitionId = obj;
	}

	static inline std::string identifier(void)
	{
		return "CommObjectRecognitionObjects::CommObjectRecognitionId";
	}

	//
	// user interfaces

	/**
	 * Set the id of the object which was recognized.
	 */
	inline void set_id(uint32_t id) {
		idl_CommObjectRecognitionId.id = id;
	}

	/**
	 * Get the id of the object which was recognized.
	 */
	inline uint32_t get_id() const {
		return idl_CommObjectRecognitionId.id;
	}

	/**
	 * Set the id of the object which was recognized in lisp syntax.
	 * Syntax:
	 * 		id(?id)
	 */
	int set(const std::string& str) {
		char *param = (char *) NULL;
		char *input = (char *) NULL;

		int error = 0;
		input = (char *) str.c_str();

		do {
			param = strsep(&input, LISP_SEPARATOR);
		} while ((param != NULL) && (strlen(param) == 0));

		// --------------------
		// set object_id
		// --------------------
		if (strcasecmp(param, "id") == 0) {
			do {
				param = strsep(&input, LISP_SEPARATOR);
			} while ((param != NULL) && (strlen(param) == 0));

			if ((sscanf(param, "%d", &idl_CommObjectRecognitionId.id) != 1)) {
				error = -1;
			}
		} else {
			error = -1;
		}

		return error;
	}

	/**
	 * Print the object to an output stream.
	 * @param os Output stream to which should be printed
	 */
	void print(std::ostream &os = std::cout) const;
};

//
// Implementation
//

inline std::ostream &operator<<(std::ostream &os, const CommObjectRecognitionId &obj) {
	obj.print(os);
	return os;
}


}
#endif
