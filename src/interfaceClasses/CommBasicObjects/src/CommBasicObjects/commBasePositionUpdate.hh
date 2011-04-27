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

// --------------------------------------------------------------------------
//
//  Copyright (C) 2003 Boris Kluge
//
//        schlegel@hs-ulm.de
//
//        Prof. Dr. Christian Schlegel
//        University of Applied Sciences
//        Prittwitzstr. 10
//        D-89075 Ulm
//        Germany
//
//  This file is part of the "SmartSoft Basic Communication Classes".
//  It provides basic standardized data types for communication between
//  different components in the mobile robotics context. These classes
//  are designed to be used in conjunction with the SmartSoft Communication
//  Library.
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
//  (partly based on work by Christian Schlegel and Pablo d'Angelo)
//
// --------------------------------------------------------------------------

#ifndef _COMM_COMMBASICOBJECTS_COMMBASEPOSITIONUPDATE_HH
#define _COMM_COMMBASICOBJECTS_COMMBASEPOSITIONUPDATE_HH

#include <string>

// include files of classes

// include header-files of included communication objects
#include <CommBasicObjects/commTimeStamp.hh>
#include <CommBasicObjects/commBasePosition.hh>

// include enums


// include client-side file generated by IDL compiler
#include "CommBasicObjects/gen/smartCommBasePositionUpdateC.hh"

namespace CommBasicObjects
{


/**
  Relative update of the base position.
  This class is used for the communication between a self localization component
  and a base server.
  An update consists of
  <ul>
    <li>an old position with an associated timestamp
        (where the robot believed to be located at the time given by the timestamp)
        and
    <li>a corrected position (where the self localization component found out that the robot
        has been at the time given by the timestamp).
  </ul>
 */
class CommBasePositionUpdate
{
protected:
	CommBasicObjectsIDL::CommBasePositionUpdate idl_CommBasePositionUpdate;

public:
	CommBasePositionUpdate()
	{
	}

	CommBasePositionUpdate(
			const CommBasicObjectsIDL::CommBasePositionUpdate &obj) :
		idl_CommBasePositionUpdate(obj)
	{
	}

	virtual ~CommBasePositionUpdate()
	{
	}

	void get(CORBA::Any &a) const;
	void set(const CORBA::Any &a);

	inline const CommBasicObjectsIDL::CommBasePositionUpdate &get() const
	{
		return idl_CommBasePositionUpdate;
	}

	inline void set(const CommBasicObjectsIDL::CommBasePositionUpdate &obj)
	{
		idl_CommBasePositionUpdate = obj;
	}

	static inline std::string identifier(void)
	{
		return "CommBasicObjects::CommBasePositionUpdate";
	}







	//
	// user interfaces
	  /**
	    Get the time stamp.
	   */
	  inline CommTimeStamp get_time_stamp() const { return CommTimeStamp(idl_CommBasePositionUpdate.time); }

	  /**
	    Get the old and inaccurate position.
	   */
	  inline CommBasePosition get_old_position() const { return CommBasePosition(idl_CommBasePositionUpdate.position); }

	  /**
	    Get the new and corrected position.
	   */
	  inline CommBasePosition get_corrected_position() const { return CommBasePosition(idl_CommBasePositionUpdate.corrected_position); }

	  /**
	    Set the time stamp.
	   */
	  inline void set_time_stamp(const CommTimeStamp &ts) { idl_CommBasePositionUpdate.time = ts.get_idl(); }

	  /**
	    Set the old and inaccurate position.
	   */
	  inline void set_old_position(const CommBasePosition &bp) { idl_CommBasePositionUpdate.position = bp.get_idl(); }

	  /**
	    Set the new and corrected position.
	   */
	  inline void set_corrected_position(const CommBasePosition &bp) { idl_CommBasePositionUpdate.corrected_position = bp.get_idl(); }

	  /**
	    Write information about this update to the given output stream.
	   */
	  void print(std::ostream &os = std::cout) const;

	  /**
	    Save an XML like representation of this base position update to the given output stream.
	   */
	  void save_xml(std::ostream &os, const std::string &indent = "") const;

	  /**
	    Load from XML represenation on an istream.
	    Be warned, no error checking is done.
	    For details, see \ref smart_basic_com-xml.
	   */
	  void load_xml(std::istream &is);

};


//
// Implementation
//

inline std::ostream &operator<<(std::ostream &os, const CommBasePositionUpdate &upd)
{
  upd.print(os);
  return os;
}



}
#endif
