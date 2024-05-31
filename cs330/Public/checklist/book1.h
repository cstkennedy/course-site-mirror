class Book {
public:
  Book (std::string theTitle,
	Author* theAuthor, 
        std::string theIdentifier);

  Book (std::string theTitle, int numberOfAuthors,
	Author** theAuthors, std::string theIdentifier);

  Book (const Book& b);

  ~Book();

  Book& operator= (const Book&);

  std::string getTitle() const        {return title;}
  void putTitle(std::string theTitle) {title = theTitle;}

  Author getAuthor () const;
  void putAuthor (Author);

  std::string getIdentifier() const   {return identifier;}
  void putIdentifier(std::string id)  {identifier = id;}

private:
  std::string title;
  int numAuthors;
  Author author;
  std::string identifier;
};
