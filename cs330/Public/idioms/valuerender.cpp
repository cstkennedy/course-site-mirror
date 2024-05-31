 string NumericValue::render(int width) const
 {
   string buffer;
   ostringstream out (buffer);
   out << d;
   return buffer.substr(0,width);
 }
 
 
 string StringValue::render(int width) const {
   return s.substr(0.width);
 }
 
 string ErrorValue::render(int width) const {
   return string("** error **").substr(0.width);
 }
