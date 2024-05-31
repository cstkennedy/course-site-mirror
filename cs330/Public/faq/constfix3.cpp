void baz (const C& c1, C& c2, const std::string& str)
{
  /*+1*/C c1Copy = c1;/*-1*/
  int i = /*+1*/c1Copy/*-1*/.foo();   // ok
  int j = c2.foo();
    /*...*/
