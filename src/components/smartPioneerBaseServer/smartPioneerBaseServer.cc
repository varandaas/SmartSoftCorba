//--------------------------------------------------------------------------
//
//  Copyright (C) 2003 Christian Schlegel, Andreas Steck
//
//        schlegel@hs-ulm.de
//        steck@hs-ulm.de
//
//        ZAFH Servicerobotic Ulm
//        University of Applied Sciences
//        Prittwitzstr. 10
//        89075 Ulm
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

//----------------------------------------------------------------------------
//
// CREDITS:
//
// The code for the communication with the pioneer robot was taken from the 
// Playerstage Project, which is distributed under GPL, and you can find at 
// http://playerstage.sourceforge.net/
//
// Player - One Hell of a Robot Server
// Copyright (C) 2000  
//    Brian Gerkey, Kasper Stoy, Richard Vaughan, & Andrew Howard
//
//----------------------------------------------------------------------------
//
// Boost Software License - Version 1.0 - August 17th, 2003
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//                   
//----------------------------------------------------------------------------

#include <string>
#include <sstream>
#include <memory>

#include "Robot.hh"

#include "smartSoft.hh"

#include "commBasePosition.hh"
#include "commBasePositionUpdate.hh"
#include "commBaseVelocity.hh"
#include "commBaseState.hh"
#include "commNavigationVelocity.hh"

#define INI_PARAMETERS_FILE "smartPioneerBaseServer.ini"


Robot robot;


// -------------------------------------------------------------
//
// Parameters
//
// -------------------------------------------------------------

/// Parameter for the verbosity.
bool param_verbose = false;
bool param_enable_motors = true;
bool param_enable_sonar = false;

int param_maxVel = 1000;
int param_maxRotVel = 300;
int param_maxVelAcc = 300;
int param_maxVelDecel = 300;
int param_maxRotVelAcc = 100;
int param_maxRotVelDecel = 100;

double param_baseStatePushTimedInterval = 100;
std::string param_serialport;

/**
 * Read the parameters.
 * The parameters are read from an ini-file.
 */
void readParameters(int argc, char **argv)
{
  CHS::SmartParameter parameter;

  try {
    parameter.addFile(argc, argv, "ini");
  } catch(CHS::ParameterError e) {
    try {
      parameter.addFile(INI_PARAMETERS_FILE);
    } catch(CHS::ParameterError e) {
      std::cerr << "No parameter file found." << std::endl;
      return;
    }
  }


  ////////////////////
  // set defaults
  //
  //param_verbose = false;
  //param_enable_motors = true;
  //param_baseStatePushTimedInterval = 100;
  //param_serialport = "dev/ttyS42";
  //param_enable_sonar = false;

  ////////////////////
  // read parameters
  //
  parameter.getTruthValue("pioneer", "enable_motors", param_enable_motors);
  std::cout << "param_enable_motors = " << param_enable_motors << std::endl;

  parameter.getTruthValue("pioneer", "enable_sonar", param_enable_sonar);
  std::cout << "param_enable_sonar = " << param_enable_sonar << std::endl;

  parameter.getTruthValue("pioneer", "verbose", param_verbose);
  std::cout << "param_verbose = " << param_verbose << std::endl;

  parameter.getString("pioneer", "serialport", param_serialport);
  std::cout << "serialPort = " << param_serialport << std::endl;

  parameter.getInt("pioneer", "maxVel", param_maxVel);
  std::cout << "maxVel = " << param_maxVel << std::endl;

  parameter.getInt("pioneer", "maxRotVel", param_maxRotVel);
  std::cout << "maxRotVel = " << param_maxRotVel << std::endl;

  parameter.getInt("pioneer", "maxVelAcc", param_maxVelAcc);
  std::cout << "maxVelAcc = " << param_maxVelAcc << std::endl;

  parameter.getInt("pioneer", "maxVelDecel", param_maxVelDecel);
  std::cout << "maxVelDecel = " << param_maxVelDecel << std::endl;

  parameter.getInt("pioneer", "maxRotVelAcc", param_maxRotVelAcc);
  std::cout << "maxRotVelAcc = " << param_maxRotVelAcc << std::endl;

  parameter.getInt("pioneer", "maxRotVelDecel", param_maxRotVelDecel);
  std::cout << "maxRotVelDecel = " << param_maxRotVelDecel << std::endl;


  parameter.getInt("baseposition", "push_interval_msec", param_baseStatePushTimedInterval);
  std::cout << "param_baseStatePushTimedInterval = " << param_baseStatePushTimedInterval << std::endl;


} // readParameters()


// -------------------------------------------------------------
// BasePositionUpdate
// -------------------------------------------------------------
/**
 * \class BasePositionUpdateSendHandler 
 */
class BasePositionUpdateSendHandler: public CHS::SendServerHandler<Smart::CommBasePositionUpdate>
{
public:
  void handleSend(const Smart::CommBasePositionUpdate &upd) throw()
  {
    // update robot pos
    robot.updatePosition( upd );
    std::cout << "update...\n";
  }
};

// -------------------------------------------------------------
// Velocity
// -------------------------------------------------------------
/**
 * \class NavigationVelocitySendHandler
 */
class NavigationVelocitySendHandler: public CHS::SendServerHandler<Smart::CommNavigationVelocity>
{
public:
  /**
   * Handler method for receiving navigation velocity orders.
   */
  void handleSend(const Smart::CommNavigationVelocity &cmd) throw()
  {
    if(param_verbose) std::cout << "BaseServer: received" << cmd << std::endl;
    // read the received CommNavigationVelocity object
    int v = cmd.get_v();
    int omega = (int)( cmd.get_omega()*180.0/M_PI);


    // set the robot's velocity
    //std::cout << "SetSpeed(" << v << ", " << omega << " )" << std::endl;
    robot.setV( (int)v );
    robot.setOmegaDeg( (int)omega );
  }
};


// -------------------------------------------------------------
// Base Position
// -------------------------------------------------------------
/**
 * \class BaseStatePushTimedHandler
 */
class BaseStatePushTimedHandler: public CHS::PushTimedHandler<Smart::CommBaseState>
{
public:
   /**
   * Constructor.
   */
  BaseStatePushTimedHandler()
  {
  }

  /**
   * Destructor.
   */
  virtual ~BaseStatePushTimedHandler() {}

  /**
   * Handler method for sending the current base state.
   */
  void handlePushTimer(CHS::PushTimedServer<Smart::CommBaseState> &server) throw()
  {
    time_stamp.set_now();  // Set the timestamp to the current time

    //base_velocity.set_v((xSpeed + ySpeed) / 2);
    base_velocity.set_v( robot.getV() );
    //base_velocity.set_omega_base(yawSpeed);
    base_velocity.set_omega_base( robot.getOmegaRad() );

    // push the objects CommBasePosition and CommBaseVelocity into the SmartSoft CommBaseState object
    base_state.set_time_stamp(time_stamp);
//    base_state.set_base_position(base_position);
    base_state.set_base_position( robot.getBasePosition() );
    base_state.set_base_velocity(base_velocity);

    // send the CommBaseState object to the client
    const CHS::StatusCode status = server.put(base_state);
    if(status!=CHS::SMART_OK)
    {
      std::cerr << "ERROR: failed to push base state (" << CHS::StatusCodeConversion(status) << ")" << std::endl;
    }
  }

private:
  Smart::CommTimeStamp time_stamp;
  Smart::CommBasePosition base_position;
  Smart::CommBaseVelocity base_velocity;
  Smart::CommBaseState base_state;
};





// -------------------------------------------------------------
//
// Main
//
// -------------------------------------------------------------
/**
 * The main function.
 * Starts the base server SmartSoft component for a Pioneer robot.
 * \param argc arguments counter.
 * \param argv arguments vector.
 */
int main (int argc, char **argv)
{
  try
  {
    CHS::SmartThreadManager *threadManager = CHS::SmartThreadManager::instance();

    CHS::SmartComponent component("smartPioneerBaseServer",argc,argv);

    readParameters(argc,argv);

    robot.openSerial( param_serialport, param_enable_motors, param_enable_sonar );
    robot.setParameters( param_maxVel, param_maxRotVel, param_maxVelAcc, param_maxVelDecel, param_maxRotVelAcc, param_maxRotVelDecel );
    robot.open();

    // BasePositionUpdate SendServer:
    BasePositionUpdateSendHandler basePositionUpdateSendHandler;
    CHS::ThreadQueueSendHandler<Smart::CommBasePositionUpdate> threadBasePositionUpdateSendHandler(basePositionUpdateSendHandler);
    CHS::SendServer<Smart::CommBasePositionUpdate> basePositionUpdateSendServer(&component, "positionUpdate", threadBasePositionUpdateSendHandler);

    // NavigationVelocity SendServer:
    NavigationVelocitySendHandler navigationVelocitySendHandler;
    CHS::ThreadQueueSendHandler<Smart::CommNavigationVelocity> threadNavigationVelocitySendHandler(navigationVelocitySendHandler);
    CHS::SendServer<Smart::CommNavigationVelocity> navigationVelocitySendServer(&component, "navigationvelocity", threadNavigationVelocitySendHandler);

    // BasePosition PushTimedServer: 
    BaseStatePushTimedHandler baseStatePushTimedHandler;
    CHS::ThreadQueuePushTimedHandler<Smart::CommBaseState> threadBaseStatePushTimedHandler(baseStatePushTimedHandler);
    CHS::PushTimedServer<Smart::CommBaseState> basePositionPushTimedServer(&component, "basestate", threadBaseStatePushTimedHandler, param_baseStatePushTimedInterval / 1000.0);

    // Start push services
    basePositionPushTimedServer.start();

    // Start communication: hand over control to SmartSoft
    component.run();


    threadManager->wait();

  }
  catch (const CORBA::Exception &)
  {
    std::cerr << "Uncaught CORBA exception" << std::endl;
    return 1;
  }
  catch (...)
  {
    std::cerr << "Uncaught exception" << std::endl;
    return 1;
  }

  return 0;
}
