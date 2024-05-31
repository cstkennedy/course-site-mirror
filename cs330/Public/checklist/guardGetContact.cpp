#include "mailinglist.h"
#include <cassert>

using namespace std;


Contact& MailingList::getContact (const Name& name) const
{
  ML_Node* current = first;
  while (current != NULL
	 && name > current->contact.getName())
    {
      previous = current;
      current = current->next;
    }
  /*+1*/assert (current != NULL 
		&& name == current->contact.getName());/*-1*/
  return current->contact;
}
   /*...*/
