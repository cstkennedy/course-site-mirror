class Address {
public:
  Address (std::string theStreet, std::string theCity,
           std::string theState, std::string theZip);

/*+1*/
  Address& operator= (const Address&);/*-1*/
     /*...*/
