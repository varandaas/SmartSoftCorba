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
//  Copyright (C) 2010 Andreas Steck
//
//        schlegel@hs-ulm.de
//        steck@hs-ulm.de
//
//        ZAFH Servicerobotik Ulm
//        University of Applied Sciences
//        Prittwitzstr. 10
//        D-89075 Ulm
//        Germany
//
//  This file is part of the "SmartSoft STT Dummy component".
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
// --------------------------------------------------------------------------


#include "ParameterHandler.hh"
#include "gen/SmartSTTDummy.hh"

#include "CommSpeechObjects/commSpeechInputParameter.hh"

#include <iostream>

void ParameterHandler::handleSend(
		const CommSpeechObjects::CommSpeechInputParameter &r) throw()
{
    CommSpeechObjects::SpeechInputTagType tag;
	std::string p1;
	r.get(tag, p1);

	switch (tag) {
		/////////////////////////////////////////////////////////////////////
		// SPEECH_SET_GRAMMAR

		//case Smart::SPEECH_SET_GRAMMAR: {
		case CommSpeechObjects::SpeechInputTagType::SPEECH_SET_GRAMMAR:
			std::cout << "SPEECH_SET_GRAMMAR " << "Parameters: " << p1 << " \n";
			break;

		/////////////////////////////////////////////////////////////////////
		// default
		default:
			break;
	} // switch
}
