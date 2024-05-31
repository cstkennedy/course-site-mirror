  Book *bPointer = new Book(text361); // initialized using copy constructor
      /*...*/
  cout << bPointer->getTitle() << endl;
/*+1*/  bPointer->~Book();
  free(bPointer);  // recover memory at the address in bPointer
/*-1*/
