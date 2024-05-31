#ifndef MAILINGLIST_H
#define MAILINGLIST_H

#include <iostream>
#include <string>

#include "contact.h"

/**
   A collection of names and addresses
*/
class MailingList
{
public:
  MailingList();
  MailingList(/*+2*/const MailingList&/*-2*/);
  ~MailingList();

  const MailingList& operator= (/*+2*/const MailingList&/*-2*/);

  // Add a new contact to the list
  void addContact (/*+2*/const Contact&/*-2*/ contact);

  // Remove one matching contact
  void removeContact (/*+2*/const Contact&/*-2*/);
  void removeContact (/*+2*/const Name&/*-2*/);

  // Find and retrieve contacts
  bool contains (/*+2*/const Name&/*-2*/ name) /*+3*/const/*-3*/;
  Contact getContact (/*+2*/const Name&/*-2*/ name) /*+3*/const/*-3*/;


  // combine two mailing lists
  void merge (/*+2*/const MailingList&/*-2*/ otherList);

  // How many contacts in list?
  int size() /*+3*/const/*-3*/;


  bool operator== (/*+2*/const MailingList&/*-2*/ right) /*+3*/const/*-3*/;
  bool operator< (/*+2*/const MailingList&/*-2*/ right) /*+3*/const/*-3*/;

private:

  struct ML_Node {
    Contact contact;
    ML_Node* next;

    ML_Node (/*+2*/const Contact&/*-2*/ c, /*+1*/ML_Node*/*-1*/ nxt)
      : contact(c), next(nxt)
    {}
  };

  int theSize;
  ML_Node* first;
  ML_Node* last;

  // helper functions
  void clear();
  void remove (/*+1*/ML_Node*/*-1*/ previous, /*+1*/ML_Node*/*-1*/ current);

  friend std::ostream& operator<< (std::ostream& out, /*+2*/const MailingList&/*-2*/ addr);
};

// print list, sorted by Contact
std::ostream& operator<< (std::ostream& out, /*+2*/const MailingList&/*-2*/ list);


#endif
