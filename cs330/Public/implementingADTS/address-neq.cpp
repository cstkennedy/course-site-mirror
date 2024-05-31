class Address
{
    /*...*/
  bool operator== (const Address&) const;

  /*+1*/bool operator!= (const Address& a) const {return !operator==(a);} /*-1*/
    /*...*/
};
