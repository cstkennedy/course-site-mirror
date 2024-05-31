ostream& operator<< (ostream& out, const Book& b)
{
  out << b.getISBN() << "\n";
  out << b.getTitle() << "\n";
  for (AuthorPosition current = b.begin(); current != b.end(); ++current)
  {
    Author au = *current;
    /*+1*/out << au << ", ";/*-1*/;
  }
  out << "\n  published by" << b.getPublisher();
  out << endl;
  /*+2*/return out;/*-2*/
}
