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
//  This file is part of the "SmartSoft Basic Communication Classes".
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
//  (partly based on work by Christian Schlegel and Pablo d'Angelo)
//
// --------------------------------------------------------------------------

#include "smartKnuthMorrisPratt.hh"
#include "commLaserTrackingData.hh"

using namespace Smart;

void CommLaserTrackingData::get(CORBA::Any &a) const
{
  a <<= _data;
}

void CommLaserTrackingData::set(const CORBA::Any &a)
{
  SmartIDL::LaserTrackingData *tmp_data;
  if(a >>= tmp_data)
  {
    _data = *tmp_data;
  }
}

void CommLaserTrackingData::print(std::ostream &os) const
{
  const unsigned int n = get_num_objects();
  os << "CommLaserTrackingData(" 
     << "scan=" << get_laser_scan() << ", " 
     << "#obj=" << n << ", objs={";
  for(unsigned int i = 0; i<n; ++i)
  {
    os << "(" << get_object_first_point(i) << "," << get_object_last_point(i) << ")";
  }
  os << "})";
}

void CommLaserTrackingData::save_xml(std::ostream &os, const std::string &indent) const
{
  const unsigned int n = get_num_objects();
  os << indent << "<laser_tracking_data>" << std::endl;
  get_laser_scan().save_xml(os, indent + "  ");
  os << indent << "  <objects n=\"" << n << "\">" << std::endl;
  for(unsigned int i=0; i<n; ++i)
  {
    os << indent << "    <object first=\"" << get_object_first_point(i) << "\" last=\"" << get_object_last_point(i) << "\" id=\"" << get_object_id(i) << "\"/>" << std::endl;
  }
  os << indent << "  </objects>" << std::endl;
  os << indent << "</laser_tracking_data>" << std::endl;
}

void CommLaserTrackingData::load_xml(std::istream &is)
{
  static const KnuthMorrisPratt kmp_begin("<laser_tracking_data>");
  static const KnuthMorrisPratt kmp_objects("<objects n=\"");
  static const KnuthMorrisPratt kmp_first("<object first=\"");
  static const KnuthMorrisPratt kmp_last("last=\"");
  static const KnuthMorrisPratt kmp_id("id=\"");
  static const KnuthMorrisPratt kmp_end("</laser_tracking_data>");

  kmp_begin.search(is);

  CommMobileLaserScan scan;
  scan.load_xml(is);
  set_laser_scan(scan);

  unsigned int n;
  kmp_objects.search(is);
  is >> n;
  set_num_objects(n);
  
  unsigned int first, last, id;
  for(unsigned int i=0; i<n; ++i)
  {
    kmp_first.search(is);
    is >> first;
    kmp_last.search(is);
    is >> last;
    kmp_id.search(is);
    is >> id;
    set_object_id(i,id);
    set_object_first_point(i,first);
    set_object_last_point(i,last);
  }

  kmp_end.search(is);
}
