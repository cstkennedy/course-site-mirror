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
  MailingList(const MailingList&);
  ~MailingList();

  const MailingList& operator= (const MailingList&);

  // Add a new contact to the list
  void addContact (const Contact& contact);

  // Remove one matching contact
  void removeContact (const Contact&);
  void removeContact (const Name&);

  // Find and retrieve contacts
  bool contains (const Name& name) const;
  Contact getContact (const Name& name) const;


  // combine two mailing lists
  void merge (const MailingList& otherList);

  // How many contacts in list?
  int size() const;


  bool operator== (const MailingList& right) const;
  bool operator< (const MailingList& right) const;

private:

  struct ML_Node {
    Contact contact;
    ML_Node* next;

    ML_Node (const Contact& c, ML_Node* nxt)
      : contact(c), next(nxt)
    {}
  };

  int theSize;
  ML_Node* first;
  ML_Node* last;

  // helper functions
  void clear();
  void remove (ML_Node* previous, ML_Node* current);

  friend std::ostream& operator<< (std::ostream& out, const MailingList& addr);
};

// print list, sorted by Contact
std::ostream& operator<< (std::ostream& out, const MailingList& list);


#endif
