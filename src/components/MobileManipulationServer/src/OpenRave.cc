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
//        Christian Schlegel (schlegel@hs-ulm.de)
//        University of Applied Sciences
//        Prittwitzstr. 10
//        89075 Ulm (Germany)
//
//  This file is part of the "Katana Mobile Manipulation component".
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

// this include must be the first one
#include "controller/MainController.hh"

#include "OpenRave.hh"
#include "gen/MobileManipulationServer.hh"

#include <iostream>
#include <mrpt/core.h>

using namespace mrpt::math;

void OpenRave::handleQuery(CHS::QueryServer<Smart::CommMoMaObjectList,
		Smart::CommMoMaManipulateState> & server, const CHS::QueryId id,
		const Smart::CommMoMaObjectList & request) throw ()
{
	Smart::CommMoMaManipulateState answer;

	std::vector<uint32_t> ids;
	std::string state;
	double motor01;
	double motor02;
	double motor03;
	double motor04;
	double motor05;
	uint32_t command;

	answer.setSize(request.getObjectListSize());

	for (unsigned int i=0; i < request.getObjectListSize(); i++)
	{
		ids.push_back(request.getId(i));
	}


	mmp::MainController::getInstance().beginManipulation(ids);
	for (unsigned int i=0; i < request.getObjectListSize(); i++)
	{
		// get motor angles directly or calculate first
		if (request.getFlags(i) == 0)
		{
			std::vector<double> angles;
			double x;
			double y;
			double z;
			double yaw;
			double pitch;
			double roll;

			request.getPose(i, x, y, z, yaw, pitch, roll);
			mmp::MainController::getInstance().calculateIK(x, y, z, yaw, pitch, roll, angles);

			if (angles.size() < 5)
			{
				break;
			}

			motor01 = angles[0];
			motor02 = angles[1];
			motor03 = angles[2];
			motor04 = angles[3];
			motor05 = angles[4];
		}
		else if (request.getFlags(i) == 1)
		{
			request.getMotors(i, motor01, motor02, motor03, motor04, motor05);
		}

		// get command
		command = request.getCommand(i);

		std::string objClass;
		request.getObjectClass(i, objClass);

		cout << "Id, Class: " << request.getId(i) << ", " << objClass << endl;
		state = mmp::MainController::getInstance().manipulateObject(request.getId(i), motor01, motor02, motor03, motor04, motor05, command);

		answer.setObjectId(i, request.getId(i));
		answer.setState(i, state);
	}
	mmp::MainController::getInstance().endManipulation();

	server.answer(id, answer);
}
