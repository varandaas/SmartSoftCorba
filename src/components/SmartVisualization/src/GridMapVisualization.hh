// --------------------------------------------------------------------------
//
//  Copyright (C) 2011 Manuel Wopfner
//
//        schlegel@hs-ulm.de
//
//        ZAFH Servicerobotik Ulm
//        University of Applied Sciences
//        Prittwitzstr. 10
//        D-89075 Ulm
//        Germany
//
//  This file is part of the "SmartSoft Communication Classes".
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
// --------------------------------------------------------------------------

#ifndef GRIDMAPVISUALIZATION_H_
#define GRIDMAPVISUALIZATION_H_

#include "AbstractVisualization.hh"

#include "CommNavigationObjects/commGridMap.hh"
#include "CommNavigationObjects/commGridMapRequest.hh"

class GridMapVisualization: public AbstractVisualization {

private:
	bool showAxis;
	bool activateTransparency;
//	CDisplayWindow w1;
//	CDisplayWindow w2;

public:
	GridMapVisualization(CDisplayWindow3D& window3D, const std::string& identifier, bool showAxis = false, bool activateTransparency =
			false);
	virtual ~GridMapVisualization();

	void displayGridMap(const CommNavigationObjects::CommGridMap& map);
	void clear();
};

#endif /* GRIDMAPVISUALIZATION_H_ */
