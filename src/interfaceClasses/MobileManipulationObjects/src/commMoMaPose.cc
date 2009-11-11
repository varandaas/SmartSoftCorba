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
//  This file is part of the "Katana Mobile Manipulation communication objects".
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
#include "commMoMaPose.hh"

using namespace Smart;

void CommMoMaPose::get(CORBA::Any &a) const {
	a <<= moMaPose;
}

void CommMoMaPose::set(const CORBA::Any &a) {
	SmartIDL::MoMaPose *tmp_cmd;
	if (a >>= tmp_cmd) {
		moMaPose = *tmp_cmd;
	}
}

void CommMoMaPose::setX(double value) {
	moMaPose.x = value;
}

double CommMoMaPose::getX() const {
	return moMaPose.x;
}

void CommMoMaPose::setY(double value) {
	moMaPose.y = value;
}

double CommMoMaPose::getY() const {
	return moMaPose.y;
}

void CommMoMaPose::setZ(double value) {
	moMaPose.z = value;
}

double CommMoMaPose::getZ() const {
	return moMaPose.z;
}

void CommMoMaPose::setYaw(double value) {
	moMaPose.yaw = value;
}

double CommMoMaPose::getYaw() const {
	return moMaPose.yaw;
}

void CommMoMaPose::setPitch(double value) {
	moMaPose.pitch = value;
}

double CommMoMaPose::getPitch() const {
	return moMaPose.pitch;
}

void CommMoMaPose::setRoll(double value) {
	moMaPose.roll = value;
}

double CommMoMaPose::getRoll() const {
	return moMaPose.roll;
}

void CommMoMaPose::setMotor1(double value) {
	moMaPose.motor01 = value;
}

double CommMoMaPose::getMotor1() const {
	return moMaPose.motor01;
}

void CommMoMaPose::setMotor2(double value) {
	moMaPose.motor02 = value;
}

double CommMoMaPose::getMotor2() const {
	return moMaPose.motor02;
}

void CommMoMaPose::setMotor3(double value) {
	moMaPose.motor03 = value;
}

double CommMoMaPose::getMotor3() const {
	return moMaPose.motor03;
}

void CommMoMaPose::setMotor4(double value) {
	moMaPose.motor04 = value;
}

double CommMoMaPose::getMotor4() const {
	return moMaPose.motor04;
}

void CommMoMaPose::setMotor5(double value) {
	moMaPose.motor05 = value;
}

double CommMoMaPose::getMotor5() const {
	return moMaPose.motor05;
}

void CommMoMaPose::setMotors(double motor01, double motor02, double motor03,
		double motor04, double motor05) {
	moMaPose.motor01 = motor01;
	moMaPose.motor02 = motor02;
	moMaPose.motor03 = motor03;
	moMaPose.motor04 = motor04;
	moMaPose.motor05 = motor05;
}

void CommMoMaPose::setCommand(uint32_t id) {
	moMaPose.command = id;
}

uint32_t CommMoMaPose::getCommand() const {
	return moMaPose.command;
}

void CommMoMaPose::setFlags(int flag) {
	moMaPose.flags = flag;
}

int CommMoMaPose::getFlags() const {
	return moMaPose.flags;
}

