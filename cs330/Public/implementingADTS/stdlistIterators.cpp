Book::const_AuthorPosition Book::begin() const 
{
  return authors.begin(); 
}

Book::const_AuthorPosition Book::end() const 
{
  return authors.end(); 
}

Book::AuthorPosition Book::begin() 
{
  return authors.begin(); 
}

Book::AuthorPosition Book::end() 
{
  return authors.end(); 
}
