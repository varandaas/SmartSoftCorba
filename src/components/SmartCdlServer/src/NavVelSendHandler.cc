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

// --------------------------------------------------------------------------
//
//  Copyright (C) 2008 Christian Schlegel, Andreas Steck, Matthias Lutz
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
//  This file is part of the "SmartSoft CDL component".
//  It provides navigation services based on the CDL
//  Curvature Distance Lookup approach.
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

#include "NavVelSendHandler.hh"
#include "gen/SmartCdlServer.hh"

#include <iostream>

void NavVelSendHandler::handleSend(const CommBasicObjects::CommNavigationVelocity &r) throw()
{
    // read the received CommNavigationVelocity object
    int v = r.get_v();
    int omega = (int)( r.get_omega()*180.0/M_PI);

    // TODO
    if( COMP->globalState.strategy == CommNavigationObjects::CdlTagType::CDL_JOYSTICK )
    {
      COMP->cdlLookup->setDesiredTranslationalSpeed(v);
      //std::cout << "NavigationVelocitySendHandler::cdlLookup->setDesiredTranslationalSpeed = " << v << std::endl;
      COMP->cdlLookup->setHeading(omega);
      //std::cout << "NavigationVelocitySendHandler::cdlLookup->setHeading = " << omega << std::endl;
    }
}
