bool Address::operator== (const Address& right) const
{
  return (street == right.street)
      && (city   == right.city)
      && (state  == right.state)
      && (zip    == right.zip);
}

bool Address::operator< (const Address& right) const
{
  if (street < right.street)
    return true;
  else if (street == right.street)
    {
     if (city < right.city)
       return true;
     else if (city == right.city)
       {
        if (state < right.state)
          return true;
        else if (state == right.state)
          {
           if (zip < right.zip)
            return true;
          }
       }
    }
  return false;
}
