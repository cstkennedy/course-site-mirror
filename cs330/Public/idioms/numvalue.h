#ifndef NUMVALUE_H
#define NUMVALUE_H

#include "value.h"

//
// Numeric values in the spreadsheet.
//
class NumericValue: public Value
{
  double d;

public:
  NumericValue():d(0.0)  {}
  NumericValue (double x): d(x) {}

  virtual std::string render (unsigned maxWidth) const;
  // Produce a string denoting this value such that the
  // string's length() <= maxWidth (assuming maxWidth > 0)
  // If maxWidth==0, then the output string may be arbitrarily long.
  // This function is intended to supply the text for display in the
  // cells of a spreadsheet.


  virtual Value* clone() const;

  double getNumericValue() const {return d;}

protected:
  virtual bool isEqual (const Value& v) const;
  //pre: typeid() == v.typeid()
  //  Returns true iff this value is equal to v, using a comparison
  //  appropriate to the kind of value.

};

#endif
