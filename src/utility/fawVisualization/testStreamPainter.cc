//--------------------------------------------------------------------------
//
//  Copyright (C) 2002 Boris Kluge
//
//        schlegel@hs-ulm.de
//
//        Prof. Dr. Christian Schlegel
//        University of Applied Sciences
//        Prittwitzstr. 10
//        D-89075 Ulm
//        Germany
//
//  This file is part of the "FAW Visualization Tools".
//  Its goal is offline and online visualization of 2d geometric data
//  and its export to various graphics file formats.
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
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//--------------------------------------------------------------------------

#include <fstream>
#include <string>

#include "fawStreamPainter.hh"
#include "fawFigPainter.hh"

int main()
{
  const double polygon[4][2] = { {-1,-1}, {1,-1}, {1,1}, {-1,1} };
  const std::string basename("drawing");
  const std::string filename = basename + ".dat";
  const std::string format = "eps";

  std::ofstream ofs;
  Faw::StreamPainter sp;
  
  ofs.open(filename.c_str());
  sp.open(ofs);
  sp.draw_polygon(polygon, polygon + 4);
  sp.begin();
    sp.set_transformation(0,0,M_PI/4);
    sp.draw_chain(polygon, polygon + 4);
  sp.end();
  sp.draw_crosses(polygon + 2, polygon + 4);
  sp.draw_nodes(polygon, polygon + 2);
  sp.draw_arrow(-1,-2,1,2);
  sp.draw_ellipse(1,1,3,1,M_PI/6);
  sp.close();
  ofs.close();

  Faw::FigPainter fp;
  std::ifstream ifs;
  
  ifs.open(filename.c_str());
  Faw::StreamPainter::replay(ifs,fp);
  fp.save((basename + ".") + format,format);

  return 0;
}
