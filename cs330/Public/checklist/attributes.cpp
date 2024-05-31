class Contact {
public:
  Contact (Name nm, Address addr);

  /*+2*/const Name& name() const {return theName;}
  Name&       name()       {return theName;}/*-1*/

  /*+1*/const Address& getAddress() const {return theAddress;}
  Address&       getAddress()       {return theAddress;}/*-1*/
     /*...*/
