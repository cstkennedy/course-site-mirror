class Book {
public:
  Book (Author)                 // for books with single authors
  Book (Author[], int nAuthors) // for books with multiple authors

  std::string getTitle() const;
  void putTitle(std::string theTitle);

  int getNumberOfAuthors() const;

  std::string getIsBN() const;
  void putISBN(std::string id);

  Publisher getPublisher() const;
  void putPublisher(const Publisher& publ);

  typedef int AuthorPosition;
  <+1>Author getAuthor (AuthorPosition authorNum) const;  <-1>

  void addAuthor (AuthorPosition at, const Author& author);
  void removeAuthor (AuthorPosition at);

private:
  /*...*/
};
