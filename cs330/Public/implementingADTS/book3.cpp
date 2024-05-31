#include "authoriterator.h"
#include "book3.h"

  // for books with single authors
Book::Book (Author a)
{
  numAuthors = 1;
  first = last = new AuthorNode (a, 0, 0);
}

// for books with multiple authors
Book::Book (const Author au[], int nAuthors)
{
  numAuthors = 0;
  first = last = 0;
  for (int i = 0; i < nAuthors; ++i)
    {
      addAuthor(end(), au[i]);
    }
}


Book::AuthorPosition Book::begin() const
{
  return AuthorPosition(first);
}

Book::AuthorPosition Book::end() const
{
  return AuthorPosition(0);
}


void Book::addAuthor (Book::AuthorPosition at, const Author& author)
{
  if (first == 0)
     first = last = new AuthorNode (author, 0, 0);
  else if (at.pos == 0)
    {
      last->next = new AuthorNode (author, last, 0);
      last = last->next;
    }
  else
    {
      AuthorNode* newNode = new AuthorNode(author, at.pos->prev, at.pos);
      at.pos->prev = newNode;
      if (at.pos == first)
	first = newNode;
      else
	newNode->prev->next = newNode;
    }
  ++numAuthors;
}


void Book::removeAuthor (Book::AuthorPosition at)
{
  if (at.pos == first)
    {
      if (first == last)
        first = last = 0;
      else
	{
	  first = first->next;;
	  first->prev = 0;
	}
    }
  else if (at.pos == last)
    {
      last = last->prev;
      last->next = 0;
    }
  else 
    {
      AuthorNode* prv = at.pos->prev;
      AuthorNode* nxt = at.pos->next;
      prv->next = nxt;
      nxt->prev = prv;
    }
  delete at.pos;
  --numAuthors;
}


Book::Book (const Book& b)
  : title(b.title), isbn(b.isbn), publisher(b.publisher),
    numAuthors(0), first(0), last(0)
{
  for (AuthorPosition p = b.begin(); p != b.end(); ++p)
    addAuthor(end(), *p);
}

Book::~Book()
{
  AuthorPosition nxt;
  for (AuthorPosition current = begin(); current != end(); current = nxt)
    {
      nxt = current;
      ++nxt;
      delete current.pos;
    }
}

const Book& Book::operator= (const Book& b)
{
  if (this != &b)
    {
      title = b.title;
      isbn = b.isbn;
      publisher = b.publisher;
      numAuthors = 0;
      first =  last = 0;
      for (AuthorPosition p = b.begin(); p != b.end(); ++p)
	addAuthor(end(), *p);
    }
  return *this;
}
