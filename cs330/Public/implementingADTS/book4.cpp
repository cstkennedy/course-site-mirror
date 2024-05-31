#include "authoriterator.h"
#include "book4.h"

  // for books with single authors
Book::Book (Author a)
{
  numAuthors = 1;
  authors.push_back(a);
}

// for books with multiple authors
Book::Book (const Author au[], int nAuthors)
{
  numAuthors = nAuthors;
  for (int i = 0; i < nAuthors; ++i)
    {
      authors.push_back(au[i]);
    }
}


Book::const_AuthorPosition Book::begin() const
{
  return authors.begin();
}

Book::const_AuthorPosition Book::end() const
{
  return authors.end();
}


Book::AuthorPosition Book::begin()
{
  return authors.begin();
}

Book::AuthorPosition Book::end()
{
  return authors.end();
}


void Book::addAuthor (Book::AuthorPosition at, const Author& author)
{
  authors.insert (at, author);
  ++numAuthors;
}


void Book::removeAuthor (Book::AuthorPosition at)
{
  authors.erase (at);
  --numAuthors;
}


