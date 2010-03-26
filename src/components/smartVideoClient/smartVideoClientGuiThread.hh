// --------------------------------------------------------------------------
//
//  Copyright (C) 2003 Boris Kluge
//
//        schlegel@hs-ulm.de
//
//        Prof. Dr. Christian Schlegel
//        University of Applied Sciences
//        Prittwitzstr. 10
//        D-89075 Ulm
//        Germany
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//
// --------------------------------------------------------------------------

#ifndef SMART_VIDEO_CLIENT_GUI_THREAD_HH
#define SMART_VIDEO_CLIENT_GUI_THREAD_HH

#include <list>
#include <qobject.h>
#include <qevent.h>
#include <qpixmap.h>

#include "smartSoft.hh"
#include "smartQtQueryClient.hh"

#include "commVideoImage.hh"
#include "commVoid.hh"

class GuiThread: public QObject, public CHS::SmartTask
{
  Q_OBJECT
public:
  GuiThread
  (
    int argc, char **argv,
    int w, int h, Smart::CommVideoImage::Format f,
    Smart::QtQueryClient<Smart::CommMutableVideoImage,Smart::CommVoid> &image_client,
    bool verbose = false
  )
  : _argc(argc), _argv(argv),
    _width(w), _height(h), _format(f),
    _verbose(verbose),
    _video_widget(0),
    _pixmap(0),
    _image_client(image_client)
  {
  }

  int svc();

  virtual bool eventFilter(QObject *target, QEvent *event);

public slots:
  void new_image();

private:
  int _argc;
  char **_argv;

  int _width;
  int _height;
  Smart::CommVideoImage::Format _format;

  bool _verbose;

  QWidget *_video_widget;
  QPixmap *_pixmap;

  Smart::QtQueryClient<Smart::CommMutableVideoImage,Smart::CommVoid> &_image_client;

  Smart::CommResizableVideoImage *_query_image[2];
  CHS::QueryId _query_id[2];
  unsigned int _query_index;

  void _refresh(QPaintEvent *pe = 0);
};

#endif