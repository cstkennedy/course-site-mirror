std::string ErrorValue::render (unsigned maxWidth) const
  // Produce a string denoting this value such that the
  // string's length() <= maxWidth (assuming maxWidth > 0)
  // If maxWidth==0, then the output string may be arbitrarily long.
  // This function is intended to supply the text for display in the
  // cells of a spreadsheet.
{
  string s = theValueKindName;
  if (maxWidth == 0 || maxWidth > s.length())
    return s;
  else
    return s.substr(0, maxWidth);
}
