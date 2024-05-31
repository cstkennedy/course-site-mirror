Author::Author (std::string theName,
                Address theAddress, long id)
  /*+1*/: identifier (id)/*-1*/
{
  name = theName;
  address = theAddress;
}
