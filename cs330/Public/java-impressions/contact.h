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

  Contact (Name nm, Address addr)
    : theName(nm), theAddress(addr)
  {}


  Name getName() const   {return theName;}
  void setName (Name nm) {theName= nm;}

  Address getAddress() const     {return theAddress;}
  void setAddress (Address addr) {theAddress = addr;}

  bool operator== (const Contact& right) const
  {
    return theName == right.theName
      && theAddress == right.theAddress;
  }

  bool operator< (const Contact& right) const
  {
    return (theName < right.theName)
      || (theName == right.theName
      && theAddress < right.theAddress);
  }
};

inline
std::ostream& operator<< (std::ostream& out, const Contact& c)
{
  out << c.getName() << " @ " << c.getAddress();
  return out;
}



#endif
