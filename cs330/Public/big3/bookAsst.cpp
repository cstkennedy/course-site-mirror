const Book& Book::operator= (const Book& b)
{
  title = b.title;
  isbn = b.isbn;
  publisher = b.publisher;
  numAuthors = b.numAuthors;
  if (b.numAuthors > MAXAUTHORS)
    {
      MAXAUTHORS = b.MAXAUTHORS;
      delete [] authors;
      authors = new Author[MAXAUTHORS];
    }
  for (int i = 0; i < numAuthors; ++i)
    authors[i] = b.authors[i];
  return *this;
}
