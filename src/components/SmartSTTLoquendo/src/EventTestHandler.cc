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
//  Copyright (C) 2009 Andreas Steck, Matthias Lutz
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
//  This file is part of the "SmartSoft SpeechOutput component".
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

#include "EventTestHandler.hh"
#include "gen/SmartSTTLoquendo.hh"

#include <iostream>

bool EventTestHandler::testEvent(
		CommSpeechObjects::CommSpeechInputEventParameter &p,
		CommSpeechObjects::CommSpeechInputEventResult &r,
		const CommSpeechObjects::SpeechInputEventState &s) throw()
{
    std::cout << "\nevent test\n";

    std::string topic;
    std::string text;
    std::string semantic;
    double conf;
    topic    = s.get_topic();
    conf     = s.get_confidence();
    text     = s.get_text();
    semantic = s.get_semantic();

    double param_conf;
    std::string param_topic;
    param_conf  = p.get_confidence();
    param_topic = p.get_topic();

    if( (conf >= param_conf) &&
          ( (strcasecmp(param_topic.c_str(), topic.c_str()) == 0)
            || (strcasecmp(param_topic.c_str(), "") == 0)
            || (strcasecmp(param_topic.c_str(), "all") == 0)
      ))
    {
      r.set_text(text);
      r.set_confidence(conf);
      r.set_semantic(semantic);
      std::cout << "send event\n";
      return true;
    }
    else
    {
      //std::cout << "dont send event\n";
      return false;
    }

}
