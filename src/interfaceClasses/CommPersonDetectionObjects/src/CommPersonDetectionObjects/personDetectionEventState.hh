//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.10.4
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
//------------------------------------------------------------------------
//
//  Copyright (C) 2011 Manuel Wopfner
//
//        wopfner@hs-ulm.de
//
//        Christian Schlegel (schlegel@hs-ulm.de)
//        University of Applied Sciences
//        Prittwitzstr. 10
//        89075 Ulm (Germany)
//
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

#ifndef _COMM_COMMPERSONDETECTIONOBJECTS_PERSONDETECTIONEVENTSTATE_HH
#define _COMM_COMMPERSONDETECTIONOBJECTS_PERSONDETECTIONEVENTSTATE_HH

#include <vector>
#include <stdint.h>

// include files of classes

// include header-files of included communication objects

// include enums


namespace CommPersonDetectionObjects
{

class PersonDetectionEventState
{

protected:
	unsigned long environment_id;
	std::vector<unsigned long> person_id;

public:
	PersonDetectionEventState()
	{
	}
	virtual ~PersonDetectionEventState()
	{
	}

	//
	// user interfaces

	void set_environment_id(uint32_t id)
	{
		environment_id = id;
	}

	uint32_t get_environment_id() const
	{
		return environment_id;
	}

	void add_person_id(uint32_t id)
	{
		person_id.push_back(id);
	}

	size_t get_person_id_size() const
	{
		return person_id.size();
	}

	uint32_t get_person_id(size_t index) const
	{
		return person_id[index];
	}

};

}
#endif
