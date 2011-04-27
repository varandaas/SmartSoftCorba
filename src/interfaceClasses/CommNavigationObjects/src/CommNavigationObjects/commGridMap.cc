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
//  Copyright (C) 2008 Christian Schlegel, Andreas Steck
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


#include "smartKnuthMorrisPratt.hh"
#include "commGridMap.hh"

using namespace CommNavigationObjects;

void CommGridMap::get(CORBA::Any &a) const
{
	a <<= idl_CommGridMap;
}

void CommGridMap::set(const CORBA::Any &a)
{
	CommNavigationObjectsIDL::CommGridMap *tmp_cmd;
	if (a >>= tmp_cmd)
	{
		idl_CommGridMap = *tmp_cmd;
	}
}

int CommGridMap::get_parameter( unsigned int &id,
                                bool &is_valid,
                                struct timeval &time,
                                int &xOffsetMM,
                                int &yOffsetMM,
                                int &xOffsetCells,
                                int &yOffsetCells,
                                unsigned int &cellSizeMM,
                                unsigned int &xSizeMM,
                                unsigned int &ySizeMM,
                                unsigned int &xSizeCells,
                                unsigned int &ySizeCells ) const
{
  id           = idl_CommGridMap.id;
  is_valid     = idl_CommGridMap.is_valid;
  time.tv_sec  = idl_CommGridMap.time.sec;
  time.tv_usec = idl_CommGridMap.time.usec;
  xOffsetMM    = idl_CommGridMap.xOffsetMM;
  yOffsetMM    = idl_CommGridMap.yOffsetMM;
  xOffsetCells = idl_CommGridMap.xOffsetCells;
  yOffsetCells = idl_CommGridMap.yOffsetCells;
  cellSizeMM   = idl_CommGridMap.cellSizeMM;
  xSizeMM      = idl_CommGridMap.xSizeMM;
  ySizeMM      = idl_CommGridMap.ySizeMM;
  xSizeCells   = idl_CommGridMap.xSizeCells;
  ySizeCells   = idl_CommGridMap.ySizeCells;

  return 0;
}

void CommGridMap::save_xpm( std::ostream &os ) const
{
  int a;
  os << "/* XPM */\n";
  os << "static char *noname[] = {\n";
  os << "/* width height ncolors chars_per_pixel */\n";
  os << "\"" << idl_CommGridMap.xSizeCells << " " << idl_CommGridMap.ySizeCells << " 131 2\",\n";
  os << "/* colors */\n";

  // set grey values for free cells of actual map
  // 0    empty cell     => color value 255/255/255 (white)
  // ...
  // 127  occupied cell  => color value 1/1/1       (black)

  // set the fill character to '0' -> together with std::hex and std::setw(2)
  //                                  the value will be printed with length 2: 00, 01, 02, ..., 0f, 10, ...
  os << std::setfill('0');

  for (int h=0;h<128;h++)
  {
    //
    os << "\"" << std::hex << std::setw(2) << h << " c "
       << "#" << std::setw(2) << (255-2*h)
              << std::setw(2) << (255-2*h)
              << std::setw(2) << (255-2*h) << "\",\n";
  }

  // special value: obstacle (yellow) (0,255,255)
  os << "\"" << MAPPER_OBSTACLE << " c "
     << "#" << std::setw(2) << 0
            << std::setw(2) << 255
            << std::setw(2) << 255 << "\",\n";

  // special value: growing (green) (0,255,0)
  os << "\"" << MAPPER_GROWING << " c "
     << "#" << std::setw(2) << 0
            << std::setw(2) << 255
            << std::setw(2) << 0 << "\",\n";

  // special value: undeletable (red) (255,0,0)
  os << "\"" << MAPPER_UNDELETABLE << " c "
     << "#" << std::setw(2) << 255
            << std::setw(2) << 0
            << std::setw(2) << 0 << "\",\n";

  os << "/* pixels */\n";

  for (int y=(idl_CommGridMap.ySizeCells-1); y >= 0; y--)
  {
    os << "\"";
    for (unsigned int x=0; x < idl_CommGridMap.xSizeCells; x++)
    {
      a = (int)(idl_CommGridMap.cell[x+y*idl_CommGridMap.xSizeCells]);
      os << std::setw(2) <<  a;
    }
    if (y==0) {
      os << "\"\n";
    } else {
      os << "\",\n";
    }
  }

  os << "};\n";
}


void CommGridMap:: save_xml( std::ostream &os, const std::string &indent ) const
{
  os << indent << "<grid_map>" << std::endl;

  os << indent << "  <id>" << idl_CommGridMap.id << "</id>" << std::endl;
  os << indent << "  <valid>" << int(idl_CommGridMap.is_valid) << "</valid>" << std::endl;

  // timestamp
  get_time_stamp().save_xml(os, indent + "  ");

  os << indent << "  <xOffsetMM>" << int(idl_CommGridMap.xOffsetMM) << "</xOffsetMM>" << std::endl;
  os << indent << "  <yOffsetMM>" << int(idl_CommGridMap.yOffsetMM) << "</yOffsetMM>" << std::endl;
  os << indent << "  <xOffsetCells>" << int(idl_CommGridMap.xOffsetCells) << "</xOffsetCells>" << std::endl;
  os << indent << "  <yOffsetCells>" << int(idl_CommGridMap.yOffsetCells) << "</yOffsetCells>" << std::endl;
  os << indent << "  <cellSizeMM>" << int(idl_CommGridMap.cellSizeMM) << "</cellSizeMM>" << std::endl;
  os << indent << "  <xSizeMM>" << int(idl_CommGridMap.xSizeMM) << "</xSizeMM>" << std::endl;
  os << indent << "  <ySizeMM>" << int(idl_CommGridMap.ySizeMM) << "</ySizeMM>" << std::endl;
  os << indent << "  <xSizeCells>" << int(idl_CommGridMap.xSizeCells) << "</xSizeCells>" << std::endl;
  os << indent << "  <ySizeCells>" << int(idl_CommGridMap.ySizeCells) << "</ySizeCells>" << std::endl;

  // map cells
  os << indent << "  <map n=\"" << idl_CommGridMap.size << "\">" << std::endl;
  os << std::hex << std::setfill('0');
  for(unsigned int i=0; i < idl_CommGridMap.size; ++i)
  {
    os << indent << "    <cell value=\"" << std::setw(2) << (int)idl_CommGridMap.cell[i] << "\"/>" << std::endl;
  }
  os << indent << "  </map>" << std::endl;

  os << indent << "</grid_map>" << std::endl;

}


void CommGridMap:: load_xml( std::istream &is )
{
  int b;

  static const Smart::KnuthMorrisPratt kmp_begin("<grid_map>");
  static const Smart::KnuthMorrisPratt kmp_id("<id>");
  static const Smart::KnuthMorrisPratt kmp_valid("<valid>");

  static const Smart::KnuthMorrisPratt kmp_xOffsetMM("<xOffsetMM>");
  static const Smart::KnuthMorrisPratt kmp_yOffsetMM("<yOffsetMM>");
  static const Smart::KnuthMorrisPratt kmp_xOffsetCells("<xOffsetCells>");
  static const Smart::KnuthMorrisPratt kmp_yOffsetCells("<yOffsetCells>");
  static const Smart::KnuthMorrisPratt kmp_cellSizeMM("<cellSizeMM>");
  static const Smart::KnuthMorrisPratt kmp_xSizeMM("<xSizeMM>");
  static const Smart::KnuthMorrisPratt kmp_ySizeMM("<ySizeMM>");
  static const Smart::KnuthMorrisPratt kmp_xSizeCells("<xSizeCells>");
  static const Smart::KnuthMorrisPratt kmp_ySizeCells("<ySizeCells>");

  static const Smart::KnuthMorrisPratt kmp_map_cells("<map n=\"");
  static const Smart::KnuthMorrisPratt kmp_cell_value("<cell value=\"");

  static const Smart::KnuthMorrisPratt kmp_end("</grid_map>");

  kmp_begin.search(is);

  // <id>
  kmp_id.search(is);
  is >> b;
  idl_CommGridMap.id = b;

  // <valid>
  kmp_valid.search(is);
  is >> b;
  idl_CommGridMap.is_valid = (bool)b;

  // timestamp
  CommBasicObjects::CommTimeStamp ts;
  ts.load_xml(is);
  set_time_stamp(ts);

  // <xOffsetMM>
  kmp_xOffsetMM.search(is);
  is >> b;
  idl_CommGridMap.xOffsetMM = b;

  // <yOffsetMM>
  kmp_yOffsetMM.search(is);
  is >> b;
  idl_CommGridMap.yOffsetMM = b;

  // <xOffsetCells>
  kmp_xOffsetCells.search(is);
  is >> b;
  idl_CommGridMap.xOffsetCells = b;

  // <yOffsetCells>
  kmp_yOffsetCells.search(is);
  is >> b;
  idl_CommGridMap.yOffsetCells = b;

  // <cellSizeMM>
  kmp_cellSizeMM.search(is);
  is >> b;
  idl_CommGridMap.cellSizeMM = b;

  // <xSizeMM>
  kmp_xSizeMM.search(is);
  is >> b;
  idl_CommGridMap.xSizeMM = b;

  // <ySizeMM>
  kmp_ySizeMM.search(is);
  is >> b;
  idl_CommGridMap.ySizeMM = b;

  // <xSizeCells>
  kmp_xSizeCells.search(is);
  is >> b;
  idl_CommGridMap.xSizeCells = b;

  // <ySizeCells>
  kmp_ySizeCells.search(is);
  is >> b;
  idl_CommGridMap.ySizeCells = b;

  unsigned int n;
  kmp_map_cells.search(is);
  is >> n;
  idl_CommGridMap.size = n;
  idl_CommGridMap.cell.length(n);


  for(unsigned int i=0; i<n; ++i)
  {
    kmp_cell_value.search(is);
    is >> std::hex >> b;
    idl_CommGridMap.cell[i] = b;
  }

  kmp_end.search(is);

}

