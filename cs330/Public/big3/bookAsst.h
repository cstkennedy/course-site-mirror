class Book {
public:
  typedef const Author* AuthorPosition;

  Book (Author);                       // for books with single authors
  Book (const Author[], int nAuthors); // for books with multiple authors

  Book (const Book& b);
  /*+1*/const Book& operator= (const Book& b);/*-1*/

  std::string getTitle() const        { return title; }
  void setTitle(std::string theTitle) {  title = theTitle; }
     /*...*/
private:

  std::string title;
  int numAuthors;
  std::string isbn;
  Publisher publisher;

  int MAXAUTHORS;
  Author* authors;

};
