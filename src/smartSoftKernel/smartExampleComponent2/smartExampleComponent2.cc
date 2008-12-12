// --------------------------------------------------------------------------
//
//  Copyright (C) 2002/2004 Christian Schlegel
//
//        schlegel@hs-ulm.de
//
//        Prof. Dr. Christian Schlegel
//        University of Applied Sciences
//        Prittwitzstr. 10
//        D-89075 Ulm
//        Germany
//
//  This file is part of the "SmartSoft Communication Library".
//  It provides standardized patterns for communication between
//  different components.
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
//
//  (partly based on joint work with Robert W�rz)
//
// --------------------------------------------------------------------------

#include "smartSoft.hh"

#include "commExampleTime.hh"
#include "commExampleValues.hh"
#include "commExampleResult.hh"

// -------------------------------------------------------------
//
//
//
// -------------------------------------------------------------
CHS::SmartComponent *component;

CHS::QueryClient<CHS::CommExampleTime,CHS::CommExampleTime>     *timeClient;
CHS::QueryClient<CHS::CommExampleValues,CHS::CommExampleResult> *calcClient;


// -------------------------------------------------------------
//
// -------------------------------------------------------------
class UserThreadA : public CHS::SmartTask
{
public:
  UserThreadA() {};
  ~UserThreadA() {};
  int svc(void);
};

int UserThreadA::svc(void)
{
  CHS::QueryId    id1, id2;
  CHS::CommExampleTime q1,q2;
  CHS::CommExampleTime a1,a2;

  CHS::StatusCode status1, status2;

  time_t time_now;
  struct tm *time_p;

  while(1) {
    //
    // interleaved queries
    //
    time_now = time(0);
    time_p   = gmtime(&time_now);

    q1.set(time_p->tm_hour,time_p->tm_min,time_p->tm_sec);
    status1 = timeClient->queryRequest(q1,id1);

    time_now = time(0);
    time_p   = gmtime(&time_now);

    q2.set(time_p->tm_hour,time_p->tm_min,time_p->tm_sec);
    status2 = timeClient->queryRequest(q2,id2);

    std::cout << "thread A (status1, id1): " << CHS::StatusCodeConversion(status1) << " " << id1 << std::endl;
    std::cout << "thread A (status2, id2): " << CHS::StatusCodeConversion(status2) << " " << id2 << std::endl;

    status1 = timeClient->queryReceiveWait(id1,a1);
    status2 = timeClient->queryReceiveWait(id2,a2);

    if (status1 == CHS::SMART_CANCELLED) timeClient->queryDiscard(id1);
    if (status2 == CHS::SMART_CANCELLED) timeClient->queryDiscard(id2);

    std::cout << "thread A (status1, id1): " << CHS::StatusCodeConversion(status1) << " " << id1 << " "; a1.print();
    std::cout << "thread A (status2, id2): " << CHS::StatusCodeConversion(status2) << " " << id2 << " "; a2.print();
  }

  return 0;
};


// -------------------------------------------------------------
//
// -------------------------------------------------------------
class UserThreadB : public CHS::SmartTask
{
public:
  UserThreadB() {};
  ~UserThreadB() {};
  int svc(void);
};

int UserThreadB::svc(void)
{
  int i=0;
  std::list<int> l;

  CHS::CommExampleValues q;
  CHS::CommExampleResult r;
 
  CHS::QueryId    id;
  CHS::StatusCode status;

  while(1) {
    //
    // first query
    //
    l.clear();
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    q.set(l);

    std::cout << "thread B first query " << i++ << std::endl;

    status = calcClient->query(q,r);

    std::cout << "thread B first query (status): " << CHS::StatusCodeConversion(status) << " result ";r.print();

    //
    // second query
    //
    l.clear();
    l.push_back(10);
    l.push_back(11);
    l.push_back(12);

    q.set(l);

    std::cout << "thread B second query " << i++ << std::endl;

    status = calcClient->queryRequest(q,id);

    std::cout << "thread B second query request (status): " << CHS::StatusCodeConversion(status) << std::endl;
    std::cout << "thread B second query : ... request done ... " << std::endl;

    status = calcClient->queryReceiveWait(id,r);

    if (status == CHS::SMART_CANCELLED) calcClient->queryDiscard(id);

    std::cout << "thread B second query result (status): " << CHS::StatusCodeConversion(status) << " result ";r.print();
  }

  return 0;
}


// -------------------------------------------------------------
//
//
//
// -------------------------------------------------------------
int main (int argc, char *argv[])
{
  //
  //
  //
  try {
    CHS::SmartThreadManager *threadManager = CHS::SmartThreadManager::instance();

    component = new CHS::SmartComponent("exampleComponent2",argc,argv);

    timeClient = new CHS::QueryClient<CHS::CommExampleTime,CHS::CommExampleTime>(component,"exampleComponent1","time");
    calcClient = new CHS::QueryClient<CHS::CommExampleValues,CHS::CommExampleResult>(component,"exampleComponent1","calc");

    //
    //
    //
    UserThreadA user1;
    UserThreadB user2;

    //
    //
    //
    user1.open();
    user2.open();

    component->run();
    threadManager->wait();
  } catch  (const CORBA::Exception &) {
    std::cerr << "Uncaught CORBA exception" << std::endl;
    return 1;
  } catch (...) {
    std::cerr << "Uncaught exception" << std::endl;
    return 1;
  }

  return 0;
}

