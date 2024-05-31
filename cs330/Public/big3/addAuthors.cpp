void Book::addAuthor (Book::AuthorPosition at, const Author& author)
{
  if (numAuthors >= MAXAUTHORS)
    {
      Author* newAuthors = new Author[2*MAXAUTHORS];
      for (int i = 0; i < MAXAUTHORS; ++i)
	newAuthors[i] = authors[i];
      MAXAUTHORS *= 2;
      delete [] authors;
      authors = newAuthors;
    }
  int i = numAuthors;
  int atk = at - authors;
  while (i > atk) 
    {
      authors[i] = authors[i-1];
      i--;
    }
  authors[atk] = author;
  ++numAuthors;
}
