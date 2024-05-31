class Address {
public:
  Address (std::string theStreet, std::string theCity,
           std::string theState, std::string theZip);

  std::string getStreet() const;
  void putStreet (std::string theStreet);
  
  std::string getCity() const;
  void putCity (std::string theCity);
  
  std::string getState() const;
  void putState (std::string theState);
  
  std::string getZip() const;
  void putZip (std::string theZip);
  
private:
/*+1*/  std::string street;
  std::string city;
  std::string state;
  std::string zip;/*-1*/
};


class Author
{
public:
  Author (std::string theName, Address theAddress, long id);

  std::string getName() const        {return name;}
  void putName (std::string theName) {name = theName;}

  const Address& getAddress() const   {return address;}
  void putAddress (const Address& addr) {address = addr;}

  long getIdentifier() const     {return identifier;}

private:
/*+1*/  std::string name;
  Address address;
  const long identifier;/*-1*/
};
