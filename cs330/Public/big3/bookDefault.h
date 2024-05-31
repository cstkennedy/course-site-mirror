class Book {
public:
  typedef AuthorIterator AuthorPosition;

  Book (Author);                       // for books with single authors
  Book (const Author[], int nAuthors); // for books with multiple authors
/*+1*/  Book();/*-1*/

  std::string getTitle() const        { return title; }
  void setTitle(std::string theTitle) {  title = theTitle; }
      /*...*/
private:

  std::string title;
  int numAuthors;
  std::string isbn;
  Publisher publisher;

  AuthorNode* first;
  AuthorNode* last;

  friend class AuthorIterator;  
};
