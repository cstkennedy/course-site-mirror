//
class Value
{
public:
  virtual ~Value() {}

  virtual const char* valueKind() const;
  // Indicates what kind of value this is. For any two values, v1 and v2,
  // v1.valueKind() == v2.valueKind() if and only if they are of the
  // same kind (e.g., two numeric values). The actual character string
  // pointed to by valueKind() may be anything, but should be set to
  // something descriptive as an aid in identification and debugging.


  virtual std::string render (unsigned maxWidth) const;
  // Produce a string denoting this value such that the
  // string's length() <= maxWidth (assuming maxWidth > 0)
  // If maxWidth==0, then the output string may be arbitrarily long.
  // This function is intended to supply the text for display in the
  // cells of a spreadsheet.


  virtual Value* clone() const;
  // make a copy of this value

protected:
  virtual bool isEqual (const Value& v) const;
  //pre: valueKind() == v.valueKind()
  //  Returns true iff this value is equal to v, using a comparison
  //  appropriate to the kind of value.

  friend bool operator== (const Value&, const Value&);
};

inline
bool operator== (const Value& left, const Value& right)
{
  return (left.valueKind() == right.valueKind())
    && left.isEqual(right);
}
