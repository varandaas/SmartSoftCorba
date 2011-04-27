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
//------------------------------------------------------------------------

#ifndef _SMARTOPENRAVECORE_HH
#define _SMARTOPENRAVECORE_HH

#include "smartSoft.hh"

class SmartOpenRaveCore
{
private:

public:
	SmartOpenRaveCore();

	/**
	 * Modes in which the manipulator can be.
	 *
	 * SEND_TRAJECTORY:	Another trajectory can be sent. The manipulator is ready.
	 * NEUTRAL:			The manipulator is busy.
	 * FAILURE:			A failure in the manipulator has occurred.
	 */
	enum ManipulatorMode {
		SEND_TRAJECTORY,
		NEUTRAL,
		FAILURE
	};

	// Holds the current state of the manipulator
	ManipulatorMode manipulatorMode;

	// Semaphore to synchronize PathPlanningSendHandler and the ManipulatorEventClientHandler
	CHS::SmartSemaphore ManipulatorWaitSem;

	// Mutex to secure parameters
	CHS::SmartMutex ParameterMutex;
};

#endif
