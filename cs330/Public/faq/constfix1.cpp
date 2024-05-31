class C {
public:
   C();
int foo () /*+1*/const/*-1*/;  // don't change the object it's applied to
void bar (/*+1*/const/*-1*/ std::string& s);  // don't change s
   /*...*/  
}
