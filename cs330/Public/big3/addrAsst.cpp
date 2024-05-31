Address& Address::operator= (const Address& a)
{
  street = a.street;
  city = a.city;
  state = a.state;
  zip = a.zip;
  /*+1*/return *this;/*-1*/
}
