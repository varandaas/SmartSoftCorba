//--------------------------------------------------------------------------
//  Copyright (C) 2010 Jonas Brich
//
//        brich@mail.hs-ulm.de
//
//        Christian Schlegel (schlegel@hs-ulm.de)
//        University of Applied Sciences
//        Prittwitzstr. 10
//        89075 Ulm (Germany)
//
//  This file is part of the "SmartOpenRave component".
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

#ifndef _OPENRAVE_HH
#define _OPENRAVE_HH

#include "smartSoft.hh"

#include <vector>
#include <openrave-core.h>

#include "util/ErrorHandler.hh"
#include "ManipulatorFactory.hh"

#include <CommManipulationPlannerObjects/commManipulationPlannerEventState.hh>
#include <CommBasicObjects/commPose3d.hh>
#include <EulerTransformationMatrices.hh>

using namespace OpenRAVE;

#define OPENRAVE OpenRave::instance()

/**
 * This class handles all the communication from the Component to OpenRAVE.
 *
 * Currently this class is build upon OpenRAVE Revision 1518
 */
class OpenRave {
public:
	virtual ~OpenRave();

	/**
	 * Struct which holds all parameters that can be specified over the ParamServer.
	 */
	struct OpenRaveParameter {
		bool modified;

		//bool clearEnvironment;
		//bool loadEnvironmentObjectRecognition;
		//int loadEnvironmentObjectRecognition_id;

		//bool loadSingleObjectFromObjectRecognition;
		//int loadSingleObjectFromObjectRecognition_id;

		bool computeGraspTable;
		int computeGraspTable_id;

//		bool openrave_GraspObject;
//		int openrave_GraspObject_id;
//		bool openrave_ReleaseObject;
//		int openrave_ReleaseObject_id;

		//bool parallelization;

		bool simulation_test_ik_only;

		bool grasping_none;
		bool grasping_simple;
		double grasping_simple_lowerHeightBound;
		double grasping_simple_upperHeightBound;

		double grasping_simple_lowerDepthBound;
		double grasping_simple_upperDepthBound;

		double grasping_simple_lowerAngleBound;
		double grasping_simple_upperAngleBound;

		double grasping_simple_lowerRollBound;
		double grasping_simple_upperRollBound;

		bool grasping_advanced;
	};
public:

	/**
	 * Returns the singleton instance of the OpenRave
	 */
	static OpenRave* instance();

	/**
	 * Initializes all the necessary things from OpenRAVE.
	 *
	 * For example: Planner, Robot, Default Environment
	 */
	void init();

	/**
	 * Resets OpenRAVE.
	 *
	 * All objects will be deleted except the manipulator.
	 * The default environment will be loaded after cleanup
	 */
	void resetAll();

	/**
	 * Synchronizes the real manipulator with the OpenRAVE manipulator.
	 *
	 * For this the timed update of the real manipulator is get and the
	 * current joint angles and the pose (Not the TCP) of the manipulator are read.
	 * The pose is used to fit the manipulator correctly into the environment.
	 * The angles are used to set the manipulator exactly the same way as in the real world.
	 *
	 * This method should be called before a path can be planned. Furthermore it should
	 * always be called whenever this component gets the access of the real manipulator.
	 */
	void syncManipulator();

	/**
	 * Sets the parameters which came over the ParameterServer
	 *
	 * param:	parameter communications object
	 */
	void setParameter(const CommManipulationPlannerObjects::CommManipulationPlannerParameter& param);

	/**
	 * Returns the current parameter
	 */
	OpenRaveParameter getParameter() const;

	/**
	 * Moves the manipulator in OpenRAVE to the given position.
	 *
	 * angles: 		specifies a vector of joint angles which describe the position
	 * withGripper: true is movement with the gripper otherwise without
	 *
	 * This method should be called when the trajectory is executed on the real manipulator
	 * to ensure synchronization with it if a next path planning has to be performed.
	 */
	void moveManipulatorToPosition(const std::vector<dReal>& angles, bool withGripper);

	/**
	 * Moves the manipulator in OpenRAVE to the given position.
	 *
	 * trajectory: 	specifies the trajectory which the manipulator has to perform
	 * withGripper: true is movement with the gripper otherwise without
	 *
	 * This method should be called when the trajectory is executed on the real manipulator
	 * to ensure synchronization with it if a next path planning has to be performed.
	 */
	void moveManipulatorToPosition(TrajectoryBaseConstPtr trajectory, bool withGripper);

	/**
	 * Opens the gripper in OpenRAVE.
	 */
	void openGripper();

	/**
	 * Closes the gripper in OpenRAVE.
	 */
	void closeGripper();

	/**
	 * Starts the graphical user interface which visualizes everything.
	 *
	 * This method is not returning until the GUI is closed. For this,
	 * the method should be called from a separated task.
	 */
	void startGUI();

	/**
	 * Calculates the inverse kinematic to a given pose.
	 * The collision with objects at the given pose and with the robot itself are considered.
	 *
	 * x, y, z: 					coordinates of the pose in meters
	 * azimuth, elevation, roll: 	angles of the pose in rad
	 * solution: 					vector of joint angles which describes the solution of the given pose
	 *
	 * return: true if the calculation succeeds, otherwise false
	 */
	bool calculateIKSolution(const dReal& x, const dReal& y, const dReal& z, const dReal& azimuth, const dReal& elevation,
			const dReal& roll, std::vector<dReal>& solution, CommBasicObjects::CommPose3d& pose);

	/**
	 * Iterate from 0° (horizontal) to 90° (vertical) with the gripper to get a grasping position
	 *
	 * x, y, z:		coordinates of the pose in meters
	 * solution: 	vector of joint angles which describes the solution of the given pose
	 *
	 * return: true if the calculation succeeds, otherwise false
	 */
	bool iterateToGetGraspingIKSolution(const dReal& x, const dReal& y, const dReal& z, std::vector<dReal>& solution, CommBasicObjects::CommPose3d& pose);

	/**
	 * Plans the collision free path from the current position of the robot the the given joint angles.
	 *
	 * angles:		vector of joint angles which specify the end position of the tool center point of the manipulator
	 * trajectory:	trajectory filled with the intermediate points of the tool center point from the current position to the given end position.
	 * 				Each element in the trajectory contains a set of joint angles.
	 *
	 * return: true if a path could be found, otherwise false
	 */
	bool planPath(const std::vector<dReal>& angles, TrajectoryBasePtr& trajectory);

	bool getPositonOfKinbody(unsigned int objId, TransformMatrix& transform );

	// TODO:
	void testConstraint();
	void testGrasping();
	void testManipulationGraspPlanning();
	void testPython();
	//End Test

private:

	class OpenRaveGuard {
	public:
		OpenRaveGuard(EnvironmentMutex& m) :
			mutex(m), isLocked(false) {
			acquire();
		}

		~OpenRaveGuard() {
			release();
		}

		void acquire() {
			if (COMP->ini.OpenRave.debugOpenRave) {
				std::cout << "Mutex Acquiring...: Lock " << mutex.native_handle()->__data.__lock;
				std::cout << " Count: " << mutex.native_handle()->__data.__count;
				std::cout << " Owner: " << mutex.native_handle()->__data.__owner << std::endl;
			}

			if (!isLocked) {
				mutex.lock();
				isLocked = true;
			}

			if (COMP->ini.OpenRave.debugOpenRave) {
				std::cout << "Mutex Acquired: Lock " << mutex.native_handle()->__data.__lock;
				std::cout << " Count: " << mutex.native_handle()->__data.__count;
				std::cout << " Owner: " << mutex.native_handle()->__data.__owner << std::endl;
			}
		}

		void release() {
			if (COMP->ini.OpenRave.debugOpenRave) {
				std::cout << "Mutex Releasing...: Lock " << mutex.native_handle()->__data.__lock;
				std::cout << " Count: " << mutex.native_handle()->__data.__count;
				std::cout << " Owner: " << mutex.native_handle()->__data.__owner << std::endl;
			}

			if (isLocked) {
				mutex.unlock();
				isLocked = false;
			}

			if (COMP->ini.OpenRave.debugOpenRave) {
				std::cout << "Mutex Released: Lock " << mutex.native_handle()->__data.__lock;
				std::cout << " Count: " << mutex.native_handle()->__data.__count;
				std::cout << " Owner: " << mutex.native_handle()->__data.__owner << std::endl;
			}
		}

	private:
		EnvironmentMutex& mutex;
		bool isLocked;
	};

	OpenRave();


	/**
	 * Loads an single object from a given ID over the ObjectRecognition. This method will make a query to the ObjectRecognition
	 * and gets over this the object.
	 *
	 * objId:	ID which specifies the object which should be loaded
	 */

	void loadSingelObjectFromObjRecognition(unsigned int objId);



	/**
	 * Loads an environment from a given ID over the ObjectRecognition. This method will make a query to the ObjectRecognition
	 * and gets over this all the objects in the environment.
	 *
	 * envId:	ID which specifies the environment which should be loaded
	 */
	void loadEnvironment(unsigned int envId);

	/**
	 * Loads an environment with robot, default objects and other objects from a file. The current environment will be deleted.
	 *
	 * envId:	ID which specifies the environment which should be loaded
	 */
	void loadEnvironmentFromFile(unsigned int envId);

	/**
	 * Saves the complete environment with robot and all objects into a file.
	 *
	 * envId:	ID which specifies the environment
	 */
	void saveEnvironmentToFile(unsigned int envId);

	/**
	 * Adds a KinBody to the OpenRAVE environment.
	 *
	 * data:	string which holds the XML-data which specifies the object
	 * matrix:	arma matrix which specifies the pose of the object
	 */
	void addKinBody(const std::string& data, const arma::mat& matrix);

	/**
	 * Deletes a KinBody from the OpenRAVE environment.
	 *
	 * objId:	ID of the object which should be deleted
	 */
	void deleteKinBody(unsigned int objId);


	/**
	 * Grasps a KinBody in the OpenRAVE environment.
	 * The KinBody will be part of the manipulator and will be considered by planning.
	 *
	 * objId:	ID of the object which should be grasped
	 */
	void graspKinBody(unsigned int objId);

	/**
	 * Releases a KinBody in the OpenRAVE environment.
	 * The KinBody will no longer be part of the manipulator. The KinBody will be placed exactly where it is.
	 *
	 * objId:	ID of the object which should be released
	 */
	void releaseKinBody(unsigned int objId);

	/**
	 * Computes a Grasp Table to an given object.
	 *
	 * objectId: id of the object where a grasp table should be calculated
	 */
	void computeGraspTable(unsigned int objectId);

	/**
	 * Sets active DoFs of the OpenRAVE manipulator, with the gripper.
	 *
	 * This method can be called for example before the demonstration.
	 * This will sync the whole manipulator.
	 */
	void setActiveDofsWithGripper();

	/**
	 * Sets active DoFs of the OpenRAVE manipulator, without the gripper.
	 *
	 * This method should be called before the path planning.
	 */
	void setActiveDofsWithoutGripper();

	/**
	 * Copies a 4x4 arma matrix into a OpenRAVE matrix.
	 *
	 * matrix: the 4x4 arma matrix from which will be copied from
	 * transform: the copied matrix in the OpenRAVE format
	 *
	 * return: true if copy succeed, otherwise false
	 */
	bool copy4x4MatrixToTransformMatrix(const arma::mat& matrix, TransformMatrix& transform);

	/**
	 * Deletes all KinBodies in the environment.
	 * Except those KindBodies grabbed by the manipulator.
	 *
	 * withManipulator:	if true all KinBodies including the manipulator will be deleted
	 * 					if false the manipulator will not be deleted
	 * onlyManipulator:	if true only the manipulator will be deleted
	 * 					if false, nothing will happen
	 *
	 * For deleting all KinBodies including the manipulator set "withManipulator" true and "onlyManipulator" false.
	 * For deleting only KinBodies set "withManipulator" false and "onlyManipulator" false.
	 * For deleting only the manipulator set "withManipulator" false and "onlyManipulator" true. It is possible to set "withManipulator" true.
	 */
	void deleteAllKinBodies(bool withManipulator = false, bool onlyManipulator = false);

	// Singleton Instance
	static OpenRave *_instance;

	// This is the main class of OpenRAVE
	EnvironmentBasePtr environment;

	// Holds the OpenRAVE manipulator
	RobotBasePtr manipulator;
	bool initial_sync;

	// Holds the planner
	PlannerBasePtr planner;

	// Holds the problem Instance
	ProblemInstancePtr problem;

	// Holds the specific Manipulator
	SpecificManipulator::Manipulator* specificManipulator;

	/**
	 * Global OpenRave parameters which can be
	 * modified from external
	 */
	OpenRaveParameter globalParameters;

	/**
	 * Local OpenRave parameters which can not
	 * be modified from external
	 */
	OpenRaveParameter localParameters;
	//bool parallelization_initial_sync;

};

#endif /* _OPENRAVE_HH */
