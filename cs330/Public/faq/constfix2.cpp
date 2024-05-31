void baz (/*+1*/C&/*-1*/ c1, C& c2, /*+1*/std::string&/*-1*/ str)
{
  int i = c1.foo();   // ok
  int j = c2.foo();
  c2.bar(str);        // ok
    /*...*/
