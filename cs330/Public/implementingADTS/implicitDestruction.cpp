if (someTest)
  {
   Book b = text361;
   cout << b.getTitle() << endl;
/*+1*/   b.~Book();  // implicitly generated by the compiler
/*-1*/  }
