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
#include "commMoMaObjectList.hh"

using namespace Smart;

void CommMoMaObjectList::get(CORBA::Any &a) const {
	a <<= moMaObjectList;
}

void CommMoMaObjectList::set(const CORBA::Any &a) {
	SmartIDL::MoMaObjectList *tmp_cmd;
	if (a >>= tmp_cmd) {
		moMaObjectList = *tmp_cmd;
	}
}

void CommMoMaObjectList::setObjectListSize(unsigned int size) {
	moMaObjectList.objs.length(size);
}

unsigned int CommMoMaObjectList::getObjectListSize() const {
	return moMaObjectList.objs.length();
}

void CommMoMaObjectList::setId(unsigned int index, unsigned int id) {
	moMaObjectList.objs[index].id = id;
}

void CommMoMaObjectList::setObjectClass(unsigned int index,
		const std::string& objClass) {
	moMaObjectList.objs[index].objectClass = objClass.c_str();
}

void CommMoMaObjectList::setPose(unsigned int index, double x, double y,
		double z, double yaw, double pitch, double roll) {
	// set flags to pose
	moMaObjectList.objs[index].pose.flags = 0;

	moMaObjectList.objs[index].pose.x = x;
	moMaObjectList.objs[index].pose.y = y;
	moMaObjectList.objs[index].pose.z = z;

	moMaObjectList.objs[index].pose.yaw = yaw;
	moMaObjectList.objs[index].pose.pitch = pitch;
	moMaObjectList.objs[index].pose.roll = roll;
}

void CommMoMaObjectList::getPose(unsigned int index, double& x, double& y,
		double& z, double& yaw, double& pitch, double& roll) const {
	x = moMaObjectList.objs[index].pose.x;
	y = moMaObjectList.objs[index].pose.y;
	z = moMaObjectList.objs[index].pose.z;

	yaw = moMaObjectList.objs[index].pose.yaw;
	pitch = moMaObjectList.objs[index].pose.pitch;
	roll = moMaObjectList.objs[index].pose.roll;
}

void CommMoMaObjectList::setMotors(uint32_t index, double motor01,
		double motor02, double motor03, double motor04, double motor05) {
	// set flags to motor
	moMaObjectList.objs[index].pose.flags = 1;

	moMaObjectList.objs[index].pose.motor01 = motor01;
	moMaObjectList.objs[index].pose.motor02 = motor02;
	moMaObjectList.objs[index].pose.motor03 = motor03;
	moMaObjectList.objs[index].pose.motor04 = motor04;
	moMaObjectList.objs[index].pose.motor05 = motor05;
}

void CommMoMaObjectList::getMotors(uint32_t index, double& motor01,
		double& motor02, double& motor03, double& motor04, double& motor05) const {
	motor01 = moMaObjectList.objs[index].pose.motor01;
	motor02 = moMaObjectList.objs[index].pose.motor02;
	motor03 = moMaObjectList.objs[index].pose.motor03;
	motor04 = moMaObjectList.objs[index].pose.motor04;
	motor05 = moMaObjectList.objs[index].pose.motor05;
}

int CommMoMaObjectList::getFlags(uint32_t index) const {
	return moMaObjectList.objs[index].pose.flags;
}

void CommMoMaObjectList::setCommand(uint32_t index, uint32_t id) {
	moMaObjectList.objs[index].pose.command = id;
}

uint32_t CommMoMaObjectList::getCommand(uint32_t index) const {
	return moMaObjectList.objs[index].pose.command;
}

unsigned int CommMoMaObjectList::getId(unsigned int index) const {
	return moMaObjectList.objs[index].id;
}

void CommMoMaObjectList::getObjectClass(unsigned int index,
		std::string& objClass) const {
	objClass = moMaObjectList.objs[index].objectClass;
}

