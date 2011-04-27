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

#ifndef _COMM_COMMOBJECTRECOGNITIONOBJECTS_COMMOBJECTRECOGNITIONENVIRONMENT_HH
#define _COMM_COMMOBJECTRECOGNITIONOBJECTS_COMMOBJECTRECOGNITIONENVIRONMENT_HH

#include <string>

// include files of classes

// include header-files of included communication objects
#include <CommObjectRecognitionObjects/commObjectRecognitionObjectProperties.hh>

// include enums


// include client-side file generated by IDL compiler
#include "CommObjectRecognitionObjects/gen/smartCommObjectRecognitionEnvironmentC.hh"

namespace CommObjectRecognitionObjects
{

class CommObjectRecognitionEnvironment
{
protected:
	CommObjectRecognitionObjectsIDL::CommObjectRecognitionEnvironment
			idl_CommObjectRecognitionEnvironment;

public:
	CommObjectRecognitionEnvironment()
	{
	}

	CommObjectRecognitionEnvironment(
			const CommObjectRecognitionObjectsIDL::CommObjectRecognitionEnvironment &obj) :
		idl_CommObjectRecognitionEnvironment(obj)
	{
	}

	virtual ~CommObjectRecognitionEnvironment()
	{
	}

	void get(CORBA::Any &a) const;
	void set(const CORBA::Any &a);

	inline const CommObjectRecognitionObjectsIDL::CommObjectRecognitionEnvironment &get() const
	{
		return idl_CommObjectRecognitionEnvironment;
	}

	inline void set(
			const CommObjectRecognitionObjectsIDL::CommObjectRecognitionEnvironment &obj)
	{
		idl_CommObjectRecognitionEnvironment = obj;
	}

	static inline std::string identifier(void)
	{
		return "CommObjectRecognitionObjects::CommObjectRecognitionEnvironment";
	}

	//
	// user interfaces

	/**
	 * Check if this object is valid.
	 * An invalid environment may be sent if the environment id could not be resolved by the component.
	 */
	inline bool is_valid() const {
		return idl_CommObjectRecognitionEnvironment.is_valid;
	}

	/**
	 * Set the environment to valid/invalid
	 */
	inline void set_valid(bool valid) {
		idl_CommObjectRecognitionEnvironment.is_valid = valid;
	}

	/**
	 * Set the number of objects which are contained in the environment.
	 */
	inline void set_size(uint32_t size) {
		idl_CommObjectRecognitionEnvironment.objects.length(size);
	}

	/**
	 * Returns the number of objects which are contained in the environment.
	 */
	inline uint32_t get_size() const {
		return idl_CommObjectRecognitionEnvironment.objects.length();
	}

	/**
	 * Set the properties for a specific object.
	 */
	inline void set_object_properties(uint32_t index, const CommObjectRecognitionObjectProperties& obj) {
		idl_CommObjectRecognitionEnvironment.objects[index] = obj.get();
	}

	/**
	 * Returns the properties for a specific object.
	 */
	inline CommObjectRecognitionObjectProperties get_object_properties(uint32_t index) const {
		return CommObjectRecognitionObjectProperties(idl_CommObjectRecognitionEnvironment.objects[index]);
	}

};

}
#endif
