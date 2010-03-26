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
//
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
//  This file is part of CommManipulatorObjects.
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


#ifndef _COMM_COMMMANIPULATORSTATE_HH
#define _COMM_COMMMANIPULATORSTATE_HH

#include <string>
#include <math.h>

// include header-files of includes communication objects
#include <commPose3d.hh>

// include client-side file generated by IDL compiler
#include "gen/smartCommManipulatorStateC.hh"

namespace Smart
{

class CommManipulatorState
{
protected:
	SmartIDL::CommManipulatorState idl_CommManipulatorState;

public:

	enum EnumRotationFormat
	{
		ZYX, ZXZ
	};

	/**
	 * Default constructor sets the state to invalid
	 */
	CommManipulatorState()
	{
		set_valid(false);
	}

	CommManipulatorState(const SmartIDL::CommManipulatorState &obj) :
		idl_CommManipulatorState(obj)
	{
	}

	virtual ~CommManipulatorState()
	{
	}

	void get(CORBA::Any &a) const;
	void set(const CORBA::Any &a);

	inline const SmartIDL::CommManipulatorState &get() const
	{
		return idl_CommManipulatorState;
	}

	inline void set(const SmartIDL::CommManipulatorState &obj)
	{
		idl_CommManipulatorState = obj;
	}

	static inline std::string identifier(void)
	{
		return "Smart::CommManipulatorState";
	}

	//////////////////////
	// user interfaces
	//////////////////////

	/**
	 * Set the number of joints the manipulator has.
	 * @param jointCount Number of joints
	 */
	inline void set_joint_count(uint32_t jointCount)
	{
		idl_CommManipulatorState.joint_angles.length(jointCount);
	}

	/**
	 * Return the number of joints the manipulator has.
	 * @return Number of joints
	 */
	inline uint32_t get_joint_count() const
	{
		return idl_CommManipulatorState.joint_angles.length();
	}

	/**
	 * Set angle of a joint.
	 * @param joint Index of the joint
	 * @param angle Anlge for the joint [rad]
	 */
	inline void set_joint_angle(uint32_t joint, double angle)
	{
		idl_CommManipulatorState.joint_angles[joint] = angle;
	}

	/**
	 * Return the angle for a joint.
	 * @param joint Index of the joint
	 * @return Angle for the joint [rad]
	 */
	inline double get_joint_angle(uint32_t joint) const
	{
		return idl_CommManipulatorState.joint_angles[joint];
	}

	/**
	 * Set the pose of the tool center point.
	 * @param x value of the pose [mm]
	 * @param y value of the pose [mm]
	 * @param z value of the pose [mm]
	 * @param phi value of the pose [rad]
	 * @param theta value of the pose [rad]
	 * @param psi value of the pose [rad]
	 */
	inline void set_pose_TCP(double x, double y, double z, double phi,
			double theta, double psi, EnumRotationFormat rotationFormat =
					CommManipulatorState::ZYX)
	{
		idl_CommManipulatorState.pose_tcp.position.x = x;
		idl_CommManipulatorState.pose_tcp.position.y = y;
		idl_CommManipulatorState.pose_tcp.position.z = z;

		switch (rotationFormat)
		{
			case CommManipulatorState::ZYX:
			{
				idl_CommManipulatorState.pose_tcp.orientation.azimuth = phi;
				idl_CommManipulatorState.pose_tcp.orientation.elevation = theta;
				idl_CommManipulatorState.pose_tcp.orientation.roll = psi;
				break;
			}

			case CommManipulatorState::ZXZ:
			{
				// ZXZ rotation matrix
				double r[3][3];
				create_zxz_matrix(phi, theta, psi, r);

				double nTheta = -asin(r[2][0]);
				double nPsi = 0;
				double nPhi = 0;

				if (fabs(cos(nTheta)) > 1E-8)
				{
					nPsi = atan2(r[2][1] / cos(nTheta), r[2][2] / cos(nTheta));
					nPhi = atan2(r[1][0] / cos(nTheta), r[0][0] / cos(nTheta));
				}
				else
				{
					nPhi = 0;
					nPsi = atan2(r[0][1], r[0][2]);
				}

				idl_CommManipulatorState.pose_tcp.orientation.azimuth = nPhi;
				idl_CommManipulatorState.pose_tcp.orientation.elevation
						= nTheta;
				idl_CommManipulatorState.pose_tcp.orientation.roll = nPsi;
				break;
			}
		}
	}

	/**
	 * Return the pose of the tool center point.
	 * @param x value of the pose [mm]
	 * @param y value of the pose [mm]
	 * @param z value of the pose [mm]
	 * @param azimuth value of the pose [rad]
	 * @param elevation value of the pose [rad]
	 * @param roll value of the pose [rad]
	 */
	inline void get_pose_TCP(double& x, double& y, double& z, double& phi,
			double& theta, double& psi, EnumRotationFormat rotationFormat =
					CommManipulatorState::ZYX) const
	{
		x = idl_CommManipulatorState.pose_tcp.position.x;
		y = idl_CommManipulatorState.pose_tcp.position.y;
		z = idl_CommManipulatorState.pose_tcp.position.z;

		switch (rotationFormat)
		{
			case CommManipulatorState::ZYX:
				phi = idl_CommManipulatorState.pose_tcp.orientation.azimuth;
				theta = idl_CommManipulatorState.pose_tcp.orientation.elevation;
				psi = idl_CommManipulatorState.pose_tcp.orientation.roll;
				break;

			case CommManipulatorState::ZXZ:
				// ZYX rotation matrix
				double r[3][3];
				create_zyx_matrix(
						idl_CommManipulatorState.pose_tcp.orientation.azimuth,
						idl_CommManipulatorState.pose_tcp.orientation.elevation,
						idl_CommManipulatorState.pose_tcp.orientation.roll, r);

				theta = acos(r[2][2]);

				if (fabs(sin(theta)) > 1E-8)
				{
					psi = atan2(r[2][0] / sin(theta), r[2][1] / sin(theta));
					phi = -atan2(r[0][2] / sin(theta), r[1][2] / sin(theta))
							+ M_PI;
				}
				else
				{
					phi = 0;
					psi = atan2(r[1][0], r[1][1]) + M_PI;
				}

				break;
		}
	}

	/**
	 * Set the angle of the gripper.
	 * @param angle for the gripper [rad]
	 */
	inline void set_gripper_angle(double angle)
	{
		idl_CommManipulatorState.gripper_angle = angle;
	}

	/**
	 * Get the angle of the gripper.
	 * @return Angle of the gripper [rad]
	 */
	inline double get_gripper_angle() const
	{
		return idl_CommManipulatorState.gripper_angle;
	}

	/**
	 * Set the continuous id. Each object has an unique id which is
	 * incremented for each new state
	 * @param id Continuous id.
	 */
	inline void set_id(u_int32_t id)
	{
		idl_CommManipulatorState.id = id;
	}

	/**
	 * Get the continuous id. Each object has an unique id which is
	 * incremented for each new state
	 * @return Continuous id.
	 */
	inline uint32_t get_id() const
	{
		return idl_CommManipulatorState.id;
	}

	/**
	 * Set the state to valid or invalid.
	 * @param valid
	 * 			true	: state is valid
	 * 			false	: state is invalid
	 */
	inline void set_valid(bool valid)
	{
		idl_CommManipulatorState.isValid = valid;
	}

	/**
	 * Check if the state is valid.
	 * @return
	 * 			true	: state is valid
	 * 			false	: state is invalid
	 */
	inline bool is_valid() const
	{
		return idl_CommManipulatorState.isValid;
	}

	/**
	 * Print the object to an output stream.
	 * @param os Output stream to which should be printed
	 */
	void print(std::ostream &os = std::cout) const;

private:
	void create_zxz_matrix(double phi, double theta, double psi,
			double matrix[3][3]) const
	{
		matrix[0][0] = cos(psi) * cos(phi) - sin(psi) * cos(theta) * sin(phi);
		matrix[0][1] = -sin(psi) * cos(phi) - cos(psi) * cos(theta) * sin(phi);
		matrix[0][2] = sin(theta) * sin(phi);

		matrix[1][0] = cos(psi) * sin(phi) + sin(psi) * cos(theta) * cos(phi);
		matrix[1][1] = -sin(psi) * sin(phi) + cos(psi) * cos(theta) * cos(phi);
		matrix[1][2] = -sin(theta) * cos(phi);

		matrix[2][0] = sin(psi) * sin(theta);
		matrix[2][1] = cos(psi) * sin(theta);
		matrix[2][2] = cos(theta);
	}

	void create_zyx_matrix(double phi, double theta, double psi,
			double matrix[3][3]) const
	{
		matrix[0][0] = cos(theta) * cos(phi);
		matrix[0][1] = -cos(psi) * sin(phi) + sin(psi) * sin(theta) * cos(phi);
		matrix[0][2] = sin(psi) * sin(phi) + cos(psi) * sin(theta) * cos(phi);

		matrix[1][0] = cos(theta) * sin(phi);
		matrix[1][1] = cos(psi) * cos(phi) + sin(psi) * sin(theta) * sin(phi);
		matrix[1][2] = -sin(psi) * cos(phi) + cos(psi) * sin(theta) * sin(phi);

		matrix[2][0] = -sin(theta);
		matrix[2][1] = sin(psi) * cos(theta);
		matrix[2][2] = cos(psi) * cos(theta);
	}
};

//
// Implementation
//

inline std::ostream &operator<<(std::ostream &os,
		const CommManipulatorState &state)
{
	state.print(os);
	return os;
}

} // namespace Smart
#endif