//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.10.3
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
//  Copyright (C) 2011 Manuel Wopfner
//
//        ZAFH Servicerobotik Ulm
//        University of Applied Sciences
//        Prittwitzstr. 10
//        D-89075 Ulm
//        Germany
//
//  This file is part of the "SmartSoft Mapper/GridMapper component".
//  It provides mapping services based on grid maps. The current map
//  represents the latest snapshot of the local surrounding based on
//  laserscans. The current map can be preoccupied by the longterm map.
//  The longterm map is a simple occupancy grid map.
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


#include "KinectTask.hh"
#include "gen/SmartVisualization.hh"

#include <iostream>

KinectTask::KinectTask() :
	kinect(0)
{
}

void KinectTask::init()
{
	kinect = new KinectVisualization(COMP->getWindow3d(), "Kinect");
}

int KinectTask::svc()
{
	std::cout << "connecting to: " << COMP->ini.kinectPushNewestClient.serverName << "; " << COMP->ini.kinectPushNewestClient.serviceName
			<< std::endl;
	CHS::StatusCode status = COMP->kinectPushNewestClient->connect(COMP->ini.kinectPushNewestClient.serverName,
			COMP->ini.kinectPushNewestClient.serviceName);
	while (status != CHS::SMART_OK)
	{
		usleep(500000);
		status = COMP->kinectPushNewestClient->connect(COMP->ini.kinectPushNewestClient.serverName,
				COMP->ini.kinectPushNewestClient.serviceName);
	}
	std::cout << "connected.\n";
	std::cout << COMP->ini.kinectPushNewestClient.serverName << "; " << COMP->ini.kinectPushNewestClient.serviceName << " connected.\n";
	COMP->kinectPushNewestClient->subscribe();

	CommVisionObjects::CommKinectImage image;

	if (kinect != 0)
	{
		while (1)
		{
			CHS::StatusCode status = COMP->kinectPushNewestClient->getUpdateWait(image);
			if (status == CHS::SMART_OK)
			{
				std::cout << "[KinectTask] got new kinect image\n";
				kinect->displayImage(image);
			} else
			{
				std::cout << "[KinectTask] error while getting new image: " << CHS::StatusCodeConversion(status) << "\n";
			}
		}

		delete kinect;
	} else
	{
		std::cerr << "No kinect visualization available\n";
	}

	return 0;
}
