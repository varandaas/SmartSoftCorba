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
 
#ifndef FAW_DRAWING_RENDER_ACTION_HH
#define FAW_DRAWING_RENDER_ACTION_HH

#include "fawPainter.hh"
#include "fawDrawingNode.hh"
#include "fawDrawingAction.hh"

namespace Faw {

/**
  Interface for actions taking place on a scene tree.
  Implements the visitor part in the visitor design pattern (Gamma et al. 1994).
 */
class DrawingRenderAction: public DrawingAction
{
public:
  DrawingRenderAction(Painter &painter);

  void apply(const DrawingNode *node);

  virtual void process_group_begin();
  virtual void process_group_end();
  virtual void process_shape(const DrawingShapeNode *shape);
  virtual void process_transformation(const DrawingTransformationNode *xform);
  virtual void process_style(const DrawingStyleNode *style);

private:
  Painter &_painter;
};

} // namespace Faw

#endif
