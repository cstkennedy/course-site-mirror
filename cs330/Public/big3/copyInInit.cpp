Author::Author (std::string theName, 
                Address theAddress, long id)
  : name(theName), 
/*+1*/    address(theAddress),/*-1*/
    identifier(id)
{
}
