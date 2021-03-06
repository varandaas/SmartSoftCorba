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

#ifndef _COMM_COMMPTUOBJECTS_COMMPTUMOVEREQUEST_HH
#define _COMM_COMMPTUOBJECTS_COMMPTUMOVEREQUEST_HH

#include <string>
#include <iostream>

// include files of classes
// include header-files of included communication objects

// include enums
#include <CommPTUObjects/gen/enumPTUMoveFlag.hh>

// include client-side file generated by IDL compiler
#include "CommPTUObjects/gen/smartCommPTUMoveRequestC.hh"

namespace CommPTUObjects
{

class CommPTUMoveRequest
{
protected:
	CommPTUObjectsIDL::CommPTUMoveRequest idl_CommPTUMoveRequest;

public:
	CommPTUMoveRequest()
	{
	}

	CommPTUMoveRequest(const CommPTUObjectsIDL::CommPTUMoveRequest &obj) :
		idl_CommPTUMoveRequest(obj)
	{
	}

	operator CommPTUObjectsIDL::CommPTUMoveRequest() const
	{
		return idl_CommPTUMoveRequest;
	}

	virtual ~CommPTUMoveRequest()
	{
	}

	void get(CORBA::Any &a) const;
	void set(const CORBA::Any &a);

	static inline std::string identifier(void)
	{
		return "CommPTUObjects::CommPTUMoveRequest";
	}

	//
	// user interfaces

	/**
	 * Translate the PTUMoveFlag enum to a string representation.
	 */
	static std::string modeToString(PTUMoveFlag flag);


	/**
	 * Set the pan angle in rad.
	 */
	inline void set_pan(double angle) {
		idl_CommPTUMoveRequest.pan = angle;
	}

	/**
	 * Returns the pan angle in rad.
	 */
	inline double get_pan() const {
		return idl_CommPTUMoveRequest.pan;
	}

	/**
	 * Set the tilt angle in rad.
	 */
	inline void set_tilt(double angle) {
		idl_CommPTUMoveRequest.tilt = angle;
	}

	/**
	 * Returns the tilt angle in rad.
	 */
	inline double get_tilt() const {
		return idl_CommPTUMoveRequest.tilt;
	}

	/**
	 * Set the position the ptu unit should look at. The position can be in
	 * world or robot coordinate system as specified by the move mode.
	 * The unit is by default in mm.
	 */
	inline void set_position(double x, double y, double z, const double unit = 0.001) {
		idl_CommPTUMoveRequest.point.x = x * unit * 1000;
		idl_CommPTUMoveRequest.point.y = y * unit * 1000;
		idl_CommPTUMoveRequest.point.z = z * unit * 1000;
	}

	/**
	 * Returns the position the ptu unit should look at. The position can be in
	 * world or robot coordinate system as specified by the move mode.
	 * The unit is by default in mm.
	 */
	inline void get_position(double& x, double& y, double& z, const double unit = 0.001) const {
		x = idl_CommPTUMoveRequest.point.x * 0.001 / unit;
		y = idl_CommPTUMoveRequest.point.y * 0.001 / unit;
		z = idl_CommPTUMoveRequest.point.z * 0.001 / unit;
	}

	/**
	 * Define which values of the communication object should be used for
	 * moving the ptu.
	 */
	inline void set_move_mode(PTUMoveFlag flag) {
		idl_CommPTUMoveRequest.flag = flag.get_value_idl();
	}

	/**
	 * Returns the flag that inidcates which values of the communication object
	 * should be used for moving the ptu.
	 */
	inline PTUMoveFlag get_move_mode() const {
		return idl_CommPTUMoveRequest.flag;
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

inline std::ostream &operator<<(std::ostream &os, const CommPTUMoveRequest &comm) {
	comm.print(os);
	return os;
}

}
#endif
