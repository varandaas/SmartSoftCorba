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
//--------------------------------------------------------------------------
//------------------------------------------------------------------------
//
//  Copyright (C) 2011 Manuel Wopfner
//
//        wopfner@hs-ulm.de
//
//        Christian Schlegel (schlegel@hs-ulm.de)
//        University of Applied Sciences
//        Prittwitzstr. 10
//        89075 Ulm (Germany)
//
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

#ifndef _COMM_COMMPERSONDETECTIONOBJECTS_COMMDETECTEDPERSONS_HH
#define _COMM_COMMPERSONDETECTIONOBJECTS_COMMDETECTEDPERSONS_HH

#include <string>
#include <iostream>
#include "armadillo.hh"

// include files of classes

// include header-files of included communication objects
#include <CommBasicObjects/commPose3d.hh>
#include <CommBasicObjects/commBaseState.hh>

// include enums


// include client-side file generated by IDL compiler
#include "CommPersonDetectionObjects/gen/smartCommDetectedPersonC.hh"

namespace CommPersonDetectionObjects
{

class CommDetectedPerson
{
protected:
	CommPersonDetectionObjectsIDL::CommDetectedPerson idl_CommDetectedPerson;

public:
	CommDetectedPerson()
	{
	}

	CommDetectedPerson(const CommPersonDetectionObjectsIDL::CommDetectedPerson &obj) :
		idl_CommDetectedPerson(obj)
	{
	}

	operator CommPersonDetectionObjectsIDL::CommDetectedPerson() const
	{
		return idl_CommDetectedPerson;
	}

	virtual ~CommDetectedPerson()
	{
	}

	void get(CORBA::Any &a) const;
	void set(const CORBA::Any &a);

	static inline std::string identifier(void)
	{
		return "CommPersonDetectionObjects::CommDetectedPersons";
	}

	//
	// user interfaces
	//


	/*
	 * id
	 */

	inline void set_id(const uint32_t& id)
	{
		idl_CommDetectedPerson.id = id;
	}

	inline uint32_t get_id() const
	{
		return idl_CommDetectedPerson.id;
	}

	/*
	 * pose
	 */
	inline void set_pose_robot(const CommBasicObjects::CommPose3d& pose)
	{
		idl_CommDetectedPerson.pose = pose;
	}

	inline CommBasicObjects::CommPose3d get_pose_robot() const
	{
		return idl_CommDetectedPerson.pose;
	}

	inline CommBasicObjects::CommPose3d get_pose_world() const
	{

		arma::mat worldToRobotOffset;
		arma::mat robotToPersonOffset;
		arma::mat offset;

		EulerTransformationMatrices::create_zyx_matrix(idl_CommDetectedPerson.base_state.base_position.x,
				idl_CommDetectedPerson.base_state.base_position.y, idl_CommDetectedPerson.base_state.base_position.z,
				idl_CommDetectedPerson.base_state.base_position.a_base, 0, 0, worldToRobotOffset);

		EulerTransformationMatrices::create_zyx_matrix(idl_CommDetectedPerson.pose.position.x, idl_CommDetectedPerson.pose.position.y,
				idl_CommDetectedPerson.pose.position.z, idl_CommDetectedPerson.pose.orientation.azimuth,
				idl_CommDetectedPerson.pose.orientation.elevation, idl_CommDetectedPerson.pose.orientation.roll, robotToPersonOffset);

		offset = worldToRobotOffset * robotToPersonOffset;
		return CommBasicObjects::CommPose3d(offset);

	}

	/**
	 * Sets the BaseState which is needed for calculation of world coordinates.
	 *
	 * baseState: baseState which hold necessary information for calculation
	 */
	inline void set_base_state(const CommBasicObjects::CommBaseState& baseState)
	{
		idl_CommDetectedPerson.base_state = baseState;
	}

	/**
	 * Returns the BaseState
	 */
	inline CommBasicObjects::CommBaseState get_base_state() const
	{
		return CommBasicObjects::CommBaseState(idl_CommDetectedPerson.base_state);
	}

	bool is_valid() const
	{
		return idl_CommDetectedPerson.is_valid;
	}

	void set_is_valid(bool valid)
	{
		idl_CommDetectedPerson.is_valid = valid;
	}

	void print(std::ostream &os = std::cout) const;
};

inline std::ostream &operator<<(std::ostream &os, const CommPersonDetectionObjects::CommDetectedPerson &param)
{
	param.print(os);
	return os;
}

}
#endif
