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
//--------------------------------------------------------------------------

#include "ScanEventTestHandler.hh"
#include "gen/SmartKatanaServer.hh"

#include <iostream>

bool ScanEventTestHandler::testEvent(Smart::CommVoid &p, Smart::CommManipulatorId &r, const Smart::ScanEventState &s) throw() {
	bool result = true;

	r.set_id(s.get_id());
	r.set_valid(s.is_valid());

	return result;
}
