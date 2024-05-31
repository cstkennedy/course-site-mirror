class Book {
public:
  typedef const Author* AuthorPosition;

  /*+1*/Book (Author)                 // for books with single authors
  Book (Author[], int nAuthors) // for books with multiple authors
/*-1*/
  std::string getTitle() const         { return title; }
    /*...*/
