//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.10.0
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

//--------------------------------------------------------------------------
//
//  Copyright (C) 2009 Christian Schlegel, Florian Poppa
//
//        schlegel@hs-ulm.de
//        poppa@hs-ulm.de
//
//        University of Applied Sciences
//        Prittwitzstr. 10
//        D-89075 Ulm
//        Germany
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2.1
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along
//  with this library; if not, write to the Free Software Foundation, Inc.,
//  59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//--------------------------------------------------------------------------

#ifndef _GUITASK_HH
#define _GUITASK_HH

#include "gen/GuiTaskCore.hh"

// mrpt related includes
// --> we use the mrpt library for all matrix related stuff
#include <mrpt/core.h>
#include <mrpt/utils.h>

// include <curses.h> AFTER mrpt includes, otherwise you get some weired errors!
#include <ncurses.h>
#include <iostream>

#include <CommBasicObjects/commIMUData.hh>


// namespaces used
using namespace mrpt;
using namespace mrpt::utils;
using namespace mrpt::math;


class GuiTask: public GuiTaskCore
{

public:
	GuiTask();
	int svc();



	/**
	 * Calculate additional values based on the Xsens IMU data
	 * (e.g. velocities along the x,y,z-axis, position, ...)
	 */
	inline void calculateAdditionalValues(CommBasicObjects::CommIMUData&);

	//
	// ncurses stuff
	//

	/**
	 * Initialize ncurses
	 */
	void initNCurses(void);

	/**
	 * View the Xsens IMU values as well as the additional calculated values using ncurses
	 */
	inline void viewValues(CommBasicObjects::CommIMUData&);

	//
	// helper methods, getter and setter
	//

	/**
	 * Convert degrees to radians
	 */
	double degToRad(double deg) {
		return ((deg * 2.0 * M_PI) / 360.0);
	}


private:
	  /**
	   * Method to call when it is all done. Does a bit of clean-up.
	   */
	  void die();

	  // give the user the chance to quit the process
	  bool userQuit;

	  int vieweverynthvalue;
	  WINDOW* local_win;

	  //
	  // variables for additional calculations
	  //

	  // filter the acceleration values (moving average filter)
	  // data structure to save the last filterCnt values for filtering purposes
	  CMatrixDouble accelerations_to_filter;
	  // the filtered accelerations
	  CMatrixDouble accelerations_filtered;
	  // helper: index to fill the filter structure
	  int index_accelerations_to_filter;
	  // helper: used at the beginning: first filtered value available after filterCnt-1 read values
	  bool filtered_values_available;

	  // rotation matrices
	  CMatrixDouble rotation_x;
	  CMatrixDouble rotation_y;
	  CMatrixDouble rotation_z;
	  // IMU acceleration values rotated into the real world coordinate system
	  CMatrixDouble accelerations_rotated;
	  // helper to initialize rotation matrices with 0's
	  static const double init_3x3_matrix_with_0[9];

	  // helper: matrix including g value
	  CMatrixDouble eliminate_g;
	  // helper to initialize the helper :-)
	  static const double init_eliminate_g[3];

	  // calculated delta in velocity (1st integration of the accelerometer values)
	  CMatrixDouble acc_delta_velocity;
	  // velocity along (x, y, z) based on acc_delta_velocity
	  CMatrixDouble velocity;

	  // calculated delta in position (2nd integration of the accelerometer values)
	  CMatrixDouble acc_delta_position;
	  // position (x, y, z) based on acc_delta_position
	  CMatrixDouble position;





};

#endif
