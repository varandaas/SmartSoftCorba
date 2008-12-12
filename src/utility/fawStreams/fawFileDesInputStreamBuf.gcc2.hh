//--------------------------------------------------------------------------
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
//  This file is part of the "FAW Stream Classes Package".
//  It provides some iostream, streambuf and buffer classes.
//  See file README for more information.
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
 
#include <unistd.h>
#include <streambuf.h>

namespace Faw {

class FileDesInputStreamBuf: public std::streambuf
{
public:

  FileDesInputStreamBuf(int fd) 
    : _fd(fd) 
  {
    setg(0,0,0);
  }

  virtual ~FileDesInputStreamBuf()
  {
  }

  virtual int underflow()
  {
    int result = read(_fd, _buffer, BUFFER_SIZE);
    if(result>0)
    {
      setg(_buffer, _buffer, _buffer + result);
      return ((unsigned char*)_buffer)[0];
    }
    return EOF;
  }

  virtual int uflow()
  {
    const int c = underflow();
    if(c!=EOF) sbumpc();
    return c;
  }

private:
  int _fd;
  static const unsigned int BUFFER_SIZE = 512;
  char _buffer[BUFFER_SIZE];
};

} // namespace Faw
