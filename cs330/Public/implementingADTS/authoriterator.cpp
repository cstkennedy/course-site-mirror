#include "book3.h"
#include "authoriterator.h"


AuthorIterator::AuthorIterator ()
 : pos(0)
{}


Author AuthorIterator::operator*() const
{
  return pos->au;
}

const Author* AuthorIterator::operator->() const
{
  return &(pos->au);
}

const AuthorIterator& AuthorIterator::operator++()    // prefix form ++i;
{
  pos = pos->next;
  return *this;
}

AuthorIterator AuthorIterator::operator++(int) // postfix form i++;
{
  AuthorIterator oldValue = *this;
  pos = pos->next;
  return oldValue;
}


bool AuthorIterator::operator== (const AuthorIterator& ai) const
{
  return pos == ai.pos;
}

bool AuthorIterator::operator!= (const AuthorIterator& ai) const
{
  return pos != ai.pos;
}
