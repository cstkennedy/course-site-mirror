 class Value {
 public:
   virtual string render(int width) const;
 };

 class NumericValue: public Value {
 public:
   NumericValue (double dv);

   double d;
 
   string render(int width) const;
 };

 class StringValue: public Value {
 public:
   StringValue (string sv);

   string s;
 
   string render(int width) const;
 };

 class ErrorValue: public Value {
   ErrorValue ();
  
   string render(int width) const;
 };
