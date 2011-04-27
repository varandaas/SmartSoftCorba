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
//  Copyright (C) 2009 Matthias Lutz
//
//        schlegel@hs-ulm.de
//        lutz@hs-ulm.de
//
//        ZAFH Servicerobotik Ulm
//        University of Applied Sciences
//        Prittwitzstr. 10
//        D-89075 Ulm
//        Germany
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
// --------------------------------------------------------------------------


#include "ParamHandler.hh"
#include "gen/SmartGMapping.hh"

#include <iostream>

void ParamHandler::handleSend(const CommNavigationObjects::CommGMappingParameter &r) throw()
{
	//
	// handler of the send service of this component
	//

	CommNavigationObjects::GMappingTagType tag;
	int                  p1,p2,p3,p4,p5;
	std::string filename;

	r.get(tag, p1, p2, p3, p4, p5, filename);

	switch (tag)
	{
	case CommNavigationObjects::GMappingTagType::SAVE_MAP:
	{
		if(COMP->mymap==NULL)
		{
			std::cout<<"No map inizialized!"<<std::endl;
			break;
		}

		COMP->mapLock.acquire();
		// map context informations
		const unsigned map_size_x = COMP->mymap->getMapSizeX();
		const unsigned map_size_y = COMP->mymap->getMapSizeY();
		double resolution = COMP->mymap->getResolution();
		GMapping::Point origin = COMP->mymap->map2world(GMapping::IntPoint(0, 0));

		double origin_x = origin.x;
		double origin_y = origin.y;
		double origin_z = 0.0;

		bool negate = false;
		double occupied_thresh = 0.65;
		double free_thresh = 0.196;

		const char occupied = 0;
		const char unknown = 205;
		const char freeSpace = 255;

		// create a single channel image with the same size and double depth as the map
		//	IplImage* image = cvCreateImage(cvSize(map_size_x, map_size_y), IPL_DEPTH_64F, 1);
		IplImage* image = cvCreateImage(cvSize(map_size_x, map_size_y), IPL_DEPTH_8U, 1);

		// copy map into a image
		double value = 0.0;

		//				char scaledValue = 0;
		for (unsigned int y = 0; y < map_size_y; y++)
		{
			for (unsigned int x = 0; x < map_size_x; x++)
			{
				char* ptr = image->imageData + (y * image->widthStep) + x;
				value = COMP->mymap->cell((int)x, (int)y);

				/*						if(value < free_thresh && value >= 0.0) // is cell free
							{
				 *ptr = freeSpace;
							}
							else if(value > occupied_thresh) // is cell occupied
							{
				 *ptr = occupied;
							}
							else if(value < occupied_thresh && value > free_thresh)// cell state is unknown
							{
				 *ptr = unknown;
							}
							else // handle initial values lower than 0
							{
				 *ptr = unknown;
							}

				 */
				if(value < 0.0)
				{
					*ptr = unknown;
				}
				else if(value > free_thresh)
				{
					*ptr = occupied;
				}
				else
				{
					*ptr = freeSpace;
				}

			}
		}
		cvFlip(image, NULL, 0); // 0 == horizontal flip


		char  mapFileName[255];
		sprintf(mapFileName,"data/%s.pgm", filename.c_str());
		// save image to file mapAsPGM.pgm
		if(!cvSaveImage(mapFileName,image)) cout << "Could not save: data/" << filename << endl;

		// save context information in yaml format
		char  yamlFileName[255];
		sprintf(yamlFileName,"data/%s.yaml", filename.c_str());
		CvFileStorage* fs = cvOpenFileStorage( yamlFileName, 0, CV_STORAGE_WRITE);
		cvWriteString( fs, "image", mapFileName);
		cvWriteReal( fs, "resolution", resolution);

		cvWriteInt( fs, "negate", negate);
		cvWriteReal( fs, "occupied_thresh", occupied_thresh);
		cvWriteReal( fs, "free_thresh", free_thresh);
		cvReleaseFileStorage( &fs );

		ofstream myfile;
		myfile.open(yamlFileName, ios::app);
		myfile << "origin: " << "[" << origin_x << "," << origin_y << "," << origin_z << "]\n";
		myfile.close();

		// clean up image
		cvReleaseImage(&image);

		COMP->mapLock.release();

		std::cout << "GMAPPING_SAVE_MAP: saved -  data/" << filename << "\n";
		break;
	}

	default:
	{
		break;
	}

	}//switch

}