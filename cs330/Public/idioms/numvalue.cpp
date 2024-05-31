#include "numvalue.h"

#include <sstream>
#include <iomanip>
#include <cstdio>

//
// Numeric values in the spreadsheet.
//


using namespace std;

std::string NumericValue::render (unsigned maxWidth) const
  // Produce a string denoting this value such that the
  // string's length() <= maxWidth (assuming maxWidth > 0)
  // If maxWidth==0, then the output string may be arbitrarily long.
  // This function is intended to supply the text for display in the
  // cells of a spreadsheet.
{
  char buffer[256];
  for (char precision = '6'; precision > '0'; --precision)
    {
      if (maxWidth > 0)
	{
	  sprintf (buffer, "%.1u", maxWidth);
	}
      else
	buffer[0] = 0;
      string format = string("%") + buffer + "." + precision + "g";
      int width = sprintf (buffer, format.c_str(), d);
      if (maxWidth == 0 || width <= maxWidth)
	{
	  string result = buffer;
	  result.erase(0, result.find_first_not_of(" "));
	  return result;
	}
    }
  return string(maxWidth, '*');
}

bool NumericValue::isEqual (const Value& v) const
  //pre: typeid() == v.typeid()
  //  Returns true iff this value is equal to v, using a comparison
  //  appropriate to the kind of value.
{
  const NumericValue& vv = dynamic_cast<const NumericValue&>(v);
  return d == vv.d;
}


Value* NumericValue::clone() const
{
  return new NumericValue(d);
}
