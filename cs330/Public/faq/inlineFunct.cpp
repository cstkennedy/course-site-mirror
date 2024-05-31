class Foo {
private:
   int bar;
public:
   /*+1*/int getBar () {return bar;}/*-1*/  
   void setBar (int);
};

/*+2*/inline/*-2*/
void Foo::setBar (int b) {bar = b;}
