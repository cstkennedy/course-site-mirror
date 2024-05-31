const Book& Book::operator= (const Book& b)
{
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
  return *this;
}
