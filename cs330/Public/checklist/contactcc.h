#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

#include "name.h"
#include "address.h"

class Contact {
  Name theName;
  Address theAddress;

public:
  Contact (/*+1*/Name/*-1*/ nm, /*+1*/Address/*-1*/ addr)
    : theName(nm), theAddress(addr)
  {}


  Name getName() /*+3*/const/*-3*/   {return theName;}
  void setName (/*+1*/Name/*-1*/ nm) {theName= nm;}

  Address getAddress() /*+3*/const/*-3*/     {return theAddress;}
  void setAddress (/*+1*/Address/*-1*/ addr) {theAddress = addr;}

  bool operator== (/*+2*/const Contact&/*-2*/ right) /*+3*/const/*-3*/
  {
    return theName == right.theName
      && theAddress == right.theAddress;
  }

  bool operator< (/*+2*/const Contact&/*-2*/ right) /*+3*/const/*-3*/
  {
    return (theName < right.theName)
      || (theName == right.theName
	  && theAddress < right.theAddress);
  }
};

inline
std::ostream& operator<< (std::ostream& out, /*+2*/const Contact&/*-2*/ c)
{
  out << c.getName() << " @ " << c.getAddress();
  return out;
}


#endif
