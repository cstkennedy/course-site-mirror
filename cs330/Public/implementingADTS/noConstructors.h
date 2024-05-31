class Address {
public:
  std::string getStreet() const;
  void putStreet (std::string theStreet);
  
  std::string getCity() const;
  void putCity (std::string theCity);
  
  std::string getState() const;
  void putState (std::string theState);
  
  std::string getZip() const;
  void putZip (std::string theZip);
  
private:
  std::string street;
  std::string city;
  std::string state;
  std::string zip;
};


class Author
{
public:
  std::string getName() const        {return name;}
  void putName (std::string theName) {name = theName;}

  const Address& getAddress() const   {return address;}
  void putAddress (const Address& addr) {address = addr;}

  long getIdentifier() const     {return identifier;}

private:
  std::string name;
  Address address;
  const long identifier;
};
