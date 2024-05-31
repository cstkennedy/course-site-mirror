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
  std::string street;
  std::string city;
  std::string state;
  std::string zip;
};
