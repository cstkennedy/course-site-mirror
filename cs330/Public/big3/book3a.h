#ifndef BOOK_H
#include "author.h"
#include "authoriterator.h"
#include "publisher.h"


class Book {
public:
  typedef AuthorIterator AuthorPosition;

  Book (Author);                       // for books with single authors
  Book (const Author[], int nAuthors); // for books with multiple authors


  std::string getTitle() const        { return title; }

  void setTitle(std::string theTitle) {  title = theTitle; }

  int getNumberOfAuthors() const { return numAuthors; }

  std::string getISBN() const  { return isbn; }
  void setISBN(std::string id) { isbn = id; }

  Publisher getPublisher() const { return publisher; }
  void setPublisher(const Publisher& publ) { publisher = publ; }

  AuthorPosition begin() const;
  AuthorPosition end() const;

  void addAuthor (AuthorPosition at, const Author& author);
  void removeAuthor (AuthorPosition at);

private:

  std::string title;
  int numAuthors;
  std::string isbn;
  Publisher publisher;

  AuthorNode* first;
  AuthorNode* last;

  friend class AuthorIterator;  
};

#endif
