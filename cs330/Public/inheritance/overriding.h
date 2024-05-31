class A {
public:
  void foo();
  void bar();
  void baz();
};

class B: public A {
public:
  void foo();       /*1*/
  void bar(int k);  /*2*/
  void bar() const; /*3*/
};                  /*4*/
