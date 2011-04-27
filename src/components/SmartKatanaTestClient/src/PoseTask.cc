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
//--------------------------------------------------------------------------

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
//  This file is part of the "SmartKatanaTestClient component".
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

#include "PoseTask.hh"
#include "gen/SmartKatanaTestClient.hh"

#include <iostream>

PoseTask::PoseTask()
{
	std::cout << "constructor PoseTask\n";
}

int PoseTask::svc()
{
	//	Smart::CommManipulatorParameter param;
	//	std::string command = "TRAJECTORY";
	//	param.set(command);
	//	COMP->paramClient->send(param);
	//	std::cout << ">> set param: " << command << "\n";

	COMP->manipulatorStateClient->setWaitState("neutral");
	COMP->manipulatorStateClient->setWaitState("demonstration");

	int counter = 0;
	int trajectorySize = 100;

	CommManipulatorObjects::CommManipulatorTrajectory trajectory;
	trajectory.set_valid_values(CommManipulatorObjects::ManipulatorTrajectoryFlag::JOINT_ANGLES);
	trajectory.set_gripper_action(CommManipulatorObjects::ManipulatorGripperAction::ANGLE);
	trajectory.set_trajectory_size(trajectorySize);
	trajectory.set_joint_count(5);
	trajectory.set_wait_until_each_pose_reached(false);

	bool firstValue = true;

	CommManipulatorObjects::CommManipulatorTrajectory startPosition;
	startPosition.set_valid_values(CommManipulatorObjects::ManipulatorTrajectoryFlag::JOINT_ANGLES);
	startPosition.set_gripper_action(CommManipulatorObjects::ManipulatorGripperAction::OPEN_BEFORE);
	startPosition.set_trajectory_size(1);
	startPosition.set_joint_count(5);
	startPosition.set_wait_until_each_pose_reached(true);

	// activate event
	CHS::EventId id;
	CHS::StatusCode status;
	CommManipulatorObjects::CommManipulatorEventResult result;
	CommManipulatorObjects::CommManipulatorEventParameter parameter;

	parameter.set_event(CommManipulatorObjects::ManipulatorEvent::GOAL_REACHED);
	COMP->manipulatorEventClient->activate(CHS::continuous, parameter, id);

	while (1)
	{
		CommManipulatorObjects::CommMobileManipulatorState state;
		COMP->manipulatorPosePushTimedClient->getUpdate(state);

		if (firstValue && state.get_manipulator_state().is_valid())
		{
			for (uint32_t i = 0; i < state.get_manipulator_state().get_joint_count(); ++i)
			{
				startPosition.set_joint_angle(counter, i, state.get_manipulator_state().get_joint_angle(i));
			}

			firstValue = false;
		}

		if (counter < trajectorySize && state.get_manipulator_state().is_valid())
		{
			for (uint32_t i = 0; i < state.get_manipulator_state().get_joint_count(); ++i)
			{
				trajectory.set_joint_angle(counter, i, state.get_manipulator_state().get_joint_angle(i));
			}

			state.get_manipulator_state().print();

			trajectory.set_gripper_angle(counter, state.get_manipulator_state().get_gripper_angle());
			//
			//			double x, y, z, phi, theta, psi;
			//			state.get_manipulator_state().get_pose_TCP(x, y, z, phi, theta, psi);
			//			trajectory.set_pose_TCP(counter, x, y, z, phi, theta, psi);

			counter++;
		}
		else if (counter == trajectorySize)
		{
			std::cout << "switch state to trajectory\n";
			COMP->manipulatorStateClient->setWaitState("trajectory");

			// start position
			std::cout << "move to start pos\n";
			COMP->manipulatorTrajectorySendClient->send(startPosition);

			std::cout << "wait for goal\n";
			status = COMP->manipulatorEventClient->getEvent(id, result);
			if (status == CHS::SMART_OK)
			{
				std::cout << ">> Goal Reached!\n";
			}

			// recorded trajectory
			std::cout << "send trajectory\n";
			COMP->manipulatorTrajectorySendClient->send(trajectory);
			counter++;

			std::cout << "wait for goal\n";
			status = COMP->manipulatorEventClient->getEvent(id, result);
			if (status == CHS::SMART_OK)
			{
				std::cout << ">> Goal Reached!\n";
			}

			std::cout << "switch state to neutral\n";
			COMP->manipulatorStateClient->setWaitState("neutral");

		}

		usleep(100000);
	}
	return 0;
}
