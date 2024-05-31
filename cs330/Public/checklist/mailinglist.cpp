#include <cassert>
#include <iostream>
#include <string>
#include <utility>

#include "mailinglist.h"


using namespace std;
using namespace rel_ops;



MailingList::MailingList()
  : first(NULL), last(NULL), theSize(0)
{}

MailingList::MailingList(const MailingList& ml)
  : first(NULL), last(NULL), theSize(0)
{
  for (ML_Node* current = ml.first; current != NULL;
       current = current->next)
    addContact(current->contact);
}


MailingList::~MailingList()
{
  clear();
}

const MailingList& MailingList::operator= (const MailingList& ml)
{
  if (this != &ml)
    {
      clear();
      for (ML_Node* current = ml.first; current != NULL;
	   current = current->next)
	addContact(current->contact);
    }
  return *this;
}


// Add a new contact to the list
void MailingList::addContact (const Contact& contact)
{
  if (first == NULL) 
    { // add to empty list
      first = last = new ML_Node(contact, NULL);
      theSize = 1;
    }
  else if (contact > last->contact)
    { // add to end of non-empty list
      last->next = new ML_Node(contact, NULL);
      last = last->next;
      ++theSize;
    }
  else if (contact < first->contact)
    { // add to front of non-empty list
      first = new ML_Node(contact, first);
      ++theSize;
    }
  else
    { // search for place to insert
      ML_Node* previous = first;
      ML_Node* current = first->next;
      assert (current != NULL);
      while (contact < current->contact)
	{
	  previous = current;
	  current = current->next;
	  assert (current != NULL);
	}
      previous->next = new ML_Node(contact, current);
      ++theSize;
    }
}


// Remove one matching contact
void MailingList::removeContact (const Contact& contact)
{
  ML_Node* previous = NULL;
  ML_Node* current = first;
  while (current != NULL && contact > current->contact)
    {
      previous = current;
      current = current->next;
    }
  if (current != NULL && contact == current->contact)
    remove (previous, current);
}


void MailingList::removeContact (const Name& name)
{
  ML_Node* previous = NULL;
  ML_Node* current = first;
  while (current != NULL
	 && name > current->contact.getName())
    {
      previous = current;
      current = current->next;
    }
  if (current != NULL 
	 && name == current->contact.getName())
    remove (previous, current);
}



// Find and retrieve contacts
bool MailingList::contains (const Name& name) const 
{
  ML_Node* current = first;
  while (current != NULL
	 && name > current->contact.getName())
    {
      previous = current;
      current = current->next;
    }
  return (current != NULL 
	  && name == current->contact.getName());
}


Contact MailingList::getContact (const Name& name) const
{
  ML_Node* current = first;
  while (current != NULL
	 && name > current->contact.getName())
    {
      previous = current;
      current = current->next;
    }
  if (current != NULL 
	  && name == current->contact.getName())
    return current->contact;
  else
    return Contact();
}





// combine two mailing lists
void MailingList::merge (const MailingList& anotherList)
{
  // For a quick merge, we will loop around, checking the 
  // first item in each list, and always copying the smaller
  // of the two items into result
  MailingList result;
  ML_Node* thisList = first;
  const ML_Node* otherList = anotherList.first;
  while (thisList != NULL and otherList != NULL)
    {
      if (thisList->contact < otherList->contact)
	{
	  result.addContact(thisList->contact);
	  thisList = thisList->next;
	}
      else
	{
	  result.addContact(otherList->contact);
	  otherList = otherList->next;
	}
    }
  // Now, one of the two lists has been entirely copied. 
  // The other might still have stuff to copy. So we just copy
  // any remaining items from the two lists. Note that one of these
  // two loops will execute zero times.
  while (thisList != NULL)
    {
      result.addContact(thisList->contact);
      thisList = thisList->next;
    }
  while (otherList != NULL)
    {
      result.addContact(otherList->contact);
      otherList = otherList->next;
    }
  // Now result contains the merged list. Transfer that into this list.
  clear();
  first = result.first;
  last = result.last;
  theSize = result.theSize;
  result.first = result.last = NULL;
  result.theSize = 0;
}

// How many contacts in list?
int MailingList::size() const
{
  return theSize;
}


bool MailingList::operator== (const MailingList& right) const
{
  if (theSize != right.theSize) // (easy test first!)
    return false;
  else
    {
      const ML_Node* thisList = first;
      const ML_Node* otherList = right.first;
      while (thisList != NULL)
	{
	  if (thisList->contact != otherList->contact)
	    return false;
	  thisList = thisList->next;
	  otherList = otherList->next;
	}
      return true;
    }
}


bool MailingList::operator< (const MailingList& right) const
{
  if (theSize < right.theSize)
    return true;
  else
    {
      const ML_Node* thisList = first;
      const ML_Node* otherList = right.first;
      while (thisList != NULL)
	{
	  if (thisList->contact < otherList->contact)
	    return true;
	  else if (thisList->contact > otherList->contact)
	    return false;
	  thisList = thisList->next;
	  otherList = otherList->next;
	}
      return false;
    }
}


// helper functions
void MailingList::clear()
{
  ML_Node* current = first;
  while (current != NULL)
    {
      ML_Node* next = current->next;
      delete current;
      current = next;
    }
  first = last = NULL;
  theSize = 0;
}


void MailingList::remove (MailingList::ML_Node* previous,
			  MailingList::ML_Node* current)
{
  if (previous == NULL)
    { // remove front of list
      first = current->next;
      if (last == current)
	last = NULL;
      delete current;
    }
  else if (current == last)
    { // remove end of list
      last = previous;
      last->next = NULL;
      delete current;
    }
  else
    { // remove interior node
      previous->next = current->next;
      delete current;
    }
  --theSize;
}


// print list, sorted by Contact
std::ostream& operator<< (std::ostream& out, const MailingList& list)
{
  MailingList::ML_Node* current = list.first;
  while (current != NULL)
    {
      out << current->contact << "\n";
      current = current->next;
    }
  out << flush;
  return out;
}


book1.setTitle(''bogus title'');
assert (book1.getTitle() == ''bogus title'');

book2 = book1;
assert (book1 == book2);
book1.setTitle(''bogus title 2'');
assert (! (book1  == book2));



catalog.add(book1);
assert (catalog.firstBook() == book1);>



string s1, s2;
cin >> s1 >> s2;
if (s1 < s2)       ''abc'' < ''def''
                       ''abc'' < ''abcd''

    x y

Exactly one of the following is true for any x and y
    x == y
    x < y
    y < x

 namespace std{

   namespace relops {
template <class T>
bool operator!= (T left, T right)
{
  return !(left == right);
}


template <class T>
bool operator> (T left, T right)
{
  return (right < left);
}



     using namespace std::relops;
