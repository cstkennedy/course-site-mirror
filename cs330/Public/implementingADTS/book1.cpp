#include "book1.h"

  // for books with single authors
Book::Book (Author a)
{
  numAuthors = 1;
  authors[0] = a;
}

// for books with multiple authors
Book::Book (const Author au[], int nAuthors)
{
  numAuthors = nAuthors;
  for (int i = 0; i < nAuthors; ++i)
    {
      authors[i] = au[i];
    }
}

std::string Book::getTitle() const
{
  return title;
}

void Book::setTitle(std::string theTitle)
{
  title = theTitle;
}

int Book::getNumberOfAuthors() const
{
  return numAuthors;
}

std::string Book::getISBN() const
{
  return isbn;
}

void Book::setISBN(std::string id)
{
  isbn = id;
}

Publisher Book::getPublisher() const
{
  return publisher;
}

void Book::setPublisher(const Publisher& publ)
{
  publisher = publ;
}

Book::AuthorPosition Book::begin() const
{
  return authors;
}

Book::AuthorPosition Book::end() const
{
  return authors+numAuthors;
}


void Book::addAuthor (Book::AuthorPosition at, const Author& author)
{
  int i = numAuthors;
  int atk = at - authors;
  while (i >= atk) 
    {
      authors[i+1] = authors[i];
      i--;
    }
  authors[atk] = author;
  ++numAuthors;
}


void Book::removeAuthor (Book::AuthorPosition at)
{
  int atk = at - authors;
  while (atk + 1 < numAuthors)
    {
      authors[atk] = authors[atk + 1];
      ++atk;
    }
  --numAuthors;
}


