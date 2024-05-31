const Book& Book::operator= (const Book& b)
{
/*+1*/  if (this != &b)
    {/*-1*/
      title = b.title;
      isbn = b.isbn;
      publisher = b.publisher;
      numAuthors = 0;
      for (AuthorPosition p = begin(); p != end();)
        {
          AuthorPosition nxt = p;
          ++nxt;
          delete p;
          p = nxt;
        }
      first =  last = 0;
      for (AuthorPosition p = b.begin(); p != b.end(); ++p)
         addAuthor(end(), *p);
/*+1*/    }/*-1*/
  return *this;
}
