#ifndef AUTHORITERATOR_H
#define AUTHORITERATOR_H

#include "author.h"

struct AuthorNode { 
  Author au;
  AuthorNode* prev;
  AuthorNode* next;
  
  AuthorNode (Author a, AuthorNode* prv, AuthorNode* nxt)
    : au(a), prev(prv), next(nxt)
  {}
};


class AuthorIterator {
public:
  AuthorIterator ();

  Author operator*() const;
  const Author* operator->() const;
  const AuthorIterator& operator++();    // prefix form ++i;
  AuthorIterator operator++(int);        // postfix form i++;

  bool operator== (const AuthorIterator& ai) const;
  bool operator!= (const AuthorIterator& ai) const;

private:
  AuthorNode* pos;

  AuthorIterator (AuthorNode* p)
   : pos(p)
  {}

  friend class Book;
};





#endif
