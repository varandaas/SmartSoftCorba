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

#include "ParameterHandler.hh"
#include "gen/SmartMapperGridMap.hh"

#include <iostream>

void ParameterHandler::handleSend(const CommNavigationObjects::CommMapperParameter &r) throw()
{
	CommNavigationObjects::MapperTagType tag;
    std::string          filename;
    std::string          dataDir = "data/";
    int                  p1,p2,p3,p4,p5,p6,p7;


    r.get(tag,p1,p2,p3,p4,p5,filename);

    switch (tag)
    {
    case CommNavigationObjects::MapperTagType::MAPPER_CUR_PARAMETER:
    {
    	// only allowed in deactivated mode
        // p1,p2 size x,y in mm, p3,p4 position x,y in mm,p5 mapId
        COMP->MapperStateLock.acquire();
        p6 = COMP->globalState.cellSize;
        p7 = COMP->globalState.growingType;
        COMP->MapperStateLock.release();
        COMP->CurLock.acquire();
        delete COMP->currentGridMap;
        COMP->currentGridMap = new Smart::SmartCurrentGridMap(p1,p2,p3,p4,p6,p7,p5);
        COMP->CurLock.release();
        std::cout << "MAPPER_CUR_PARAMETER new SmartCurrentGridMap created.\n"
                  << "                     Parameters: " << p1 << " " << p2
                  << " " << p3 << " " << p4 << " " << p5 << " " << p6 << " " << p7 << " \n";
        break;
    }

    case CommNavigationObjects::MapperTagType::MAPPER_CUR_LTM:
    {
    	// allowed in running mode
    	// p1 0/1 to disable/enable longterm map preoccupation
    	// p2 threshold for longterm map obstacle
    	COMP->MapperStateLock.acquire();
    	COMP->globalState.curLtmState = p1;
        if(p1== 1) //set threshold only if preoccupation is enabled
        {
        	COMP->globalState.curLtmThreshold = p2;
        }
        COMP->MapperStateLock.release();
        std::cout << "MAPPER_CUR_LTM: curLtmState = " << p1 << " curLtmThreshold = " << p2 << "\n";
        break;
    }

    case CommNavigationObjects::MapperTagType::MAPPER_CUR_EMPTY:
    {
        // allowed in running mode
        // p1 0/1 to accumulate/empty current map
    	COMP->MapperStateLock.acquire();
    	COMP->globalState.curEmpty = p1;
    	COMP->MapperStateLock.release();
        std::cout << "MAPPER_CUR_EMPTY: curEmpty = " << p1 << "\n";
        break;
    }

    case CommNavigationObjects::MapperTagType::MAPPER_CUR_SAVE:
    {
        // allowed in running mode
    	filename.append(".xml");
    	filename.insert(0, dataDir);
        COMP->CurLock.acquire();
        std::ofstream myFile ( filename.c_str() , std::ios::out | std::ios::binary);
        COMP->currentGridMap->save_xml( myFile );
        myFile.close();
        COMP->CurLock.release();
        std::cout << "MAPPER_CUR_SAVE: saved -  " << filename << "\n";
        break;
    }

    case CommNavigationObjects::MapperTagType::MAPPER_CUR_SAVE_XPM:
    {
    	// allowed in running mode
    	filename.append(".xpm");
    	filename.insert(0, dataDir);
        COMP->CurLock.acquire();
        std::ofstream myFile ( filename.c_str() , std::ios::out | std::ios::binary);
        COMP->currentGridMap->save_xpm( myFile );
        myFile.close();
        COMP->CurLock.release();
        std::cout << "MAPPER_CUR_SAVE_XPM: saved -  " << filename << "\n";
        break;
    }

    case CommNavigationObjects::MapperTagType::MAPPER_CUR_LOAD:
    {
    	// only allowed in deactivated mode
        filename.append(".xml");
	    filename.insert(0, dataDir);
        COMP->CurLock.acquire();
        std::ifstream myFile ( filename.c_str() , std::ios::in | std::ios::binary);
        COMP->currentGridMap->load_xml( myFile );
        myFile.close();
        COMP->CurLock.release();
        std::cout << "MAPPER_CUR_LOAD: loaded -  " << filename << "\n";
        break;
    }

    case CommNavigationObjects::MapperTagType::MAPPER_CUR_LOAD_LTM:
    {
    	// only allowed in deactivated mode
    	COMP->CurLock.acquire();
    	COMP->currentGridMap->clearMap();
    	COMP->currentGridMap->setLtmOccupation(COMP->globalState.curLtmThreshold,
                                         *(COMP->ltmGridMap));
    	COMP->CurLock.release();
        std::cout << "MAPPER_CUR_LOAD_LTM: cur map built from ltm map -  threshold = " << COMP->globalState.curLtmThreshold << "\n";
        break;
    }

    case CommNavigationObjects::MapperTagType::MAPPER_LTM_PARAMETER:
    {
        // only allowed in deactivated mode
        // p1,p2 size x,y in mm, p3,p4 position x,y in mm,p5 mapId
    	COMP->MapperStateLock.acquire();
        p6 = COMP->globalState.cellSize;
        COMP->MapperStateLock.release();
        COMP->LtmLock.acquire();
        delete COMP->ltmGridMap;
        COMP->ltmGridMap = new Smart::SmartLtmGridMap(p1,p2,p3,p4,p6,p5);
        COMP->LtmLock.release();
        std::cout << "MAPPER_LTM_PARAMETER: new SmartLtmGridMap created.\n"
                  << "                      Parameters: " << p1 << " " << p2
                  << " " << p3 << " " << p4 << " " << p5 << " " << p6 << " \n";
        break;
    }

    case CommNavigationObjects::MapperTagType::MAPPER_LTM_INITIALIZE:
    {
        // allowed in running mode
        // p1 contains the initializing value
    	COMP->MapperStateLock.acquire();
    	COMP->ltmGridMap->clearMap(p1);
    	COMP->MapperStateLock.release();
        std::cout << "MAPPER_LTM_INITIALIZE: clearMap(" << p1 << ")\n";
        break;
    }

    case CommNavigationObjects::MapperTagType::MAPPER_LTM_SAVE:
    {
        // allowed in running mode
        filename.append(".xml");
   	    filename.insert(0, dataDir);;
        COMP->LtmLock.acquire();
        std::ofstream myFile ( filename.c_str() , std::ios::out | std::ios::binary);
        COMP->ltmGridMap->save_xml( myFile );
        myFile.close();
        COMP->LtmLock.release();
        std::cout << "MAPPER_LTM_SAVE: saved -  " << filename << "\n";
        break;
    }

    case CommNavigationObjects::MapperTagType::MAPPER_LTM_SAVE_XPM:
    {
        // allowed in running mode
    	filename.append(".xpm");
    	filename.insert(0, dataDir);
        COMP->LtmLock.acquire();
        std::ofstream myFile ( filename.c_str() , std::ios::out | std::ios::binary);
        COMP->ltmGridMap->save_xpm( myFile );
        myFile.close();
        COMP->LtmLock.release();
        std::cout << "MAPPER_LTM_SAVE_XPM: saved -  " << filename << "\n";
        break;
    }

    case CommNavigationObjects::MapperTagType::MAPPER_LTM_SAVE_YAML_PGM:
    {
      // allowed in running mode
	  filename.insert(0, dataDir);
      std::string mapFileName = filename;
      filename.append(".yaml");
      mapFileName.append(".pgm");

      COMP->LtmLock.acquire();
      std::ofstream myFile ( filename.c_str() , std::ios::out | std::ios::binary);
      COMP->ltmGridMap->save_yaml_pgm( myFile, mapFileName );
      myFile.close();
      COMP->LtmLock.release();
      std::cout << "MAPPER_LTM_SAVE_YAML_PGM: saved - " << filename << "\n";
      break;
    }

    case CommNavigationObjects::MapperTagType::MAPPER_LTM_SAVE_YAML_PPM:
     {
        // allowed in running mode
	    filename.insert(0, dataDir);
        std::string mapFileName = filename;
        filename.append(".yaml");
        mapFileName.append(".ppm");

        COMP->LtmLock.acquire();
        std::ofstream myFile ( filename.c_str() , std::ios::out | std::ios::binary);
        COMP->ltmGridMap->save_yaml_ppm( myFile, mapFileName);
        myFile.close();
        COMP->LtmLock.release();
        std::cout << "MAPPER_LTM_SAVE_YAML_PPM: saved - " << filename << "\n";
        break;
      }

    case CommNavigationObjects::MapperTagType::MAPPER_LTM_LOAD_YAML:
          {
            // only allowed in deactivated mode
            filename.append(".yaml");
    	    filename.insert(0, dataDir);
    	    COMP->LtmLock.acquire();
            COMP->ltmGridMap->load_yaml( filename );
            COMP->LtmLock.release();
            std::cout << "MAPPER_LTM_LOAD_YAML: loaded - " << filename << "\n";
            break;
          }


    case CommNavigationObjects::MapperTagType::MAPPER_LTM_LOAD:
    {
        // only allowed in deactivated mode
        filename.append(".xml");
	    filename.insert(0, dataDir);
        COMP->LtmLock.acquire();
        std::ifstream myFile ( filename.c_str() , std::ios::in | std::ios::binary);
        COMP->ltmGridMap->load_xml( myFile );
        myFile.close();
        COMP->LtmLock.release();
        std::cout << "MAPPER_LTM_LOAD: loaded -  " << filename << "\n";
        break;
    }

    default:
    {
    	break;
    }

    } // switch

}
