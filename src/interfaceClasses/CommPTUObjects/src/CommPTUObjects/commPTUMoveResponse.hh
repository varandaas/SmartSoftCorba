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

// --------------------------------------------------------------------------
//
//  Copyright (C) 2010 Manuel Wopfner
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

#ifndef _COMM_COMMPTUOBJECTS_COMMPTUMOVERESPONSE_HH
#define _COMM_COMMPTUOBJECTS_COMMPTUMOVERESPONSE_HH

#include <string>
#include <iostream>

// include files of classes

// include header-files of included communication objects
#include <CommBasicObjects/commBaseState.hh>

// include enums
#include <CommPTUObjects/gen/enumPTUMoveStatus.hh>

// include client-side file generated by IDL compiler
#include "CommPTUObjects/gen/smartCommPTUMoveResponseC.hh"

namespace CommPTUObjects
{

class CommPTUMoveResponse
{
protected:
	CommPTUObjectsIDL::CommPTUMoveResponse idl_CommPTUMoveResponse;

public:
	CommPTUMoveResponse()
	{
	}

	CommPTUMoveResponse(const CommPTUObjectsIDL::CommPTUMoveResponse &obj) :
		idl_CommPTUMoveResponse(obj)
	{
	}

	virtual ~CommPTUMoveResponse()
	{
	}

	void get(CORBA::Any &a) const;
	void set(const CORBA::Any &a);

	inline const CommPTUObjectsIDL::CommPTUMoveResponse &get() const
	{
		return idl_CommPTUMoveResponse;
	}

	inline void set(const CommPTUObjectsIDL::CommPTUMoveResponse &obj)
	{
		idl_CommPTUMoveResponse = obj;
	}

	static inline std::string identifier(void)
	{
		return "CommPTUObjects::CommPTUMoveResponse";
	}

	//
	// user interfaces

	/**
	 * Translate the PTUMoveStatus enum to a string representation.
	 */
	static std::string stateToString(PTUMoveStatus status);

	/**
	 * Set the pose of the device relative to the robot coordinate system.
	 * (in case of a moving the device the endeffector pose)
	 */
	inline void set_device_pose3d_robot(const CommBasicObjects::CommPose3d& pose) {
		idl_CommPTUMoveResponse.devicePose = pose.get_idl();
	}

	/**
	 * Get the pose of the device relative to the robot coordinate system.
	 * (in case of a moving the device the endeffector pose)
	 */
	inline const CommBasicObjects::CommPose3d get_device_pose3d_robot() const {
		return CommBasicObjects::CommPose3d(idl_CommPTUMoveResponse.devicePose);
	}

	/**
	 * Get the pose of the device relative to the world coordinate system.
	 *  (in case of a moving the device the endeffector pose)
	 */
	inline const CommBasicObjects::CommPose3d get_device_pose3d_world() const {
		arma::mat worldOffset;
		arma::mat deviceOffset;
		arma::mat offset;

		EulerTransformationMatrices::create_zyx_matrix(idl_CommPTUMoveResponse.stateBase.base_position.x,
				idl_CommPTUMoveResponse.stateBase.base_position.y, idl_CommPTUMoveResponse.stateBase.base_position.z,
				idl_CommPTUMoveResponse.stateBase.base_position.a_base, 0, 0, worldOffset);

		EulerTransformationMatrices::create_zyx_matrix(idl_CommPTUMoveResponse.devicePose.position.x,
				idl_CommPTUMoveResponse.devicePose.position.y, idl_CommPTUMoveResponse.devicePose.position.z,
				idl_CommPTUMoveResponse.devicePose.orientation.azimuth,
				idl_CommPTUMoveResponse.devicePose.orientation.elevation,
				idl_CommPTUMoveResponse.devicePose.orientation.roll, deviceOffset);

		offset = worldOffset * deviceOffset;
		return CommBasicObjects::CommPose3d(offset);
	}

	/**
	 * Set the state of the base.
	 */
	inline void set_base_state(const CommBasicObjects::CommBaseState& state) {
		idl_CommPTUMoveResponse.stateBase = state.get_idl();
	}

	/**
	 * Get the state of the base.
	 */
	inline const CommBasicObjects::CommBaseState get_base_state() const {
		return CommBasicObjects::CommBaseState(idl_CommPTUMoveResponse.stateBase);
	}

	/**
	 * Set the status of the PTU action. (Success, Failure, etc.)
	 */
	inline void set_status(CommPTUObjects::PTUMoveStatus status) {
		idl_CommPTUMoveResponse.status =  status.get_value_idl();
	}

	/**
	 * Get the status of the PTU action. (Success, Failure, etc.)
	 */
	inline PTUMoveStatus get_status() const {
		return  idl_CommPTUMoveResponse.status;
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

inline std::ostream &operator<<(std::ostream &os, const CommPTUMoveResponse &comm) {
	comm.print(os);
	return os;
}

}
#endif