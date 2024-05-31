#ifndef STRVALUE_H
#define STRVALUE_H

#include "value.h"

//
// String values in the spreadsheet.
//
class StringValue: public Value
{
  std::string s;
  static const char* theValueKindName;

public:
  StringValue()  {}
  StringValue (std::string x): s(x) {}


  virtual std::string render (unsigned maxWidth) const;
  // Produce a string denoting this value such that the
  // string's length() <= maxWidth (assuming maxWidth > 0)
  // If maxWidth==0, then the output string may be arbitrarily long.
  // This function is intended to supply the text for display in the
  // cells of a spreadsheet.


  std::string getStringValue() const {return s;}

  virtual Value* clone() const;



protected:
  virtual bool isEqual (const Value& v) const;
  //pre: valueKind() == v.valueKind()
  //  Returns true iff this value is equal to v, using a comparison
  //  appropriate to the kind of value.

};

#endif
