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

#ifndef _COMM_COMM3DPOINTCLOUD_HH
#define _COMM_COMM3DPOINTCLOUD_HH

#include <string>

// include files of classes

// include header-files of included communication objects
#include <commPosition3d.hh>

// include enums


// include client-side file generated by IDL compiler
#include "gen/smartComm3dPointCloudC.hh"

namespace Smart {

class Comm3dPointCloud {
protected:
	SmartIDL::Comm3dPointCloud idl_Comm3dPointCloud;

public:
	Comm3dPointCloud() {
	}

	Comm3dPointCloud(const SmartIDL::Comm3dPointCloud &obj) :
		idl_Comm3dPointCloud(obj) {
	}

	virtual ~Comm3dPointCloud() {
	}

	void get(CORBA::Any &a) const;
	void set(const CORBA::Any &a);

	inline const SmartIDL::Comm3dPointCloud &get() const {
		return idl_Comm3dPointCloud;
	}

	inline void set(const SmartIDL::Comm3dPointCloud &obj) {
		idl_Comm3dPointCloud = obj;
	}

	static inline std::string identifier(void) {
		return "Smart::Comm3dPointCloud";
	}

	//
	// user interfaces

	/**
	 * Set the size of the 3d point cloud.
	 * This has to be done, before setting the points.
	 */
	inline void set_size(uint32_t size) {
		idl_Comm3dPointCloud.points.length(size);
	}

	/**
	 * Returns the size of the 3d point cloud.
	 */
	inline uint32_t get_size() const {
		return idl_Comm3dPointCloud.points.length();
	}

	/**
	 * Set the x, y, z value for a point.
	 * The points must be set in the robot coordinate system.
	 * The point is specified in the given unit value (0.001 = mm)
	 */
	inline void set_point(uint32_t index, double x, double y, double z,
			const double unit = 0.001) {
		idl_Comm3dPointCloud.points[index].x = x * unit * 1000;
		idl_Comm3dPointCloud.points[index].y = y * unit * 1000;
		idl_Comm3dPointCloud.points[index].z = z * unit * 1000;
	}

	/**
	 * Returns the x, y, z value for a point.
	 * The points are returned in the robot coordinate system.
	 * The point is specified in the given unit value (0.001 = mm)
	 */
	inline void get_point(uint32_t index, double &x, double &y, double &z,
			const double unit = 0.001) const {
		x = idl_Comm3dPointCloud.points[index].x * 0.001 / unit;
		y = idl_Comm3dPointCloud.points[index].y * 0.001 / unit;
		z = idl_Comm3dPointCloud.points[index].z * 0.001 / unit;
	}

};

}
#endif
