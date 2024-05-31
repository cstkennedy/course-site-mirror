bool NumericValue::isEqual (const Value& v) const
  //pre: valueKind() == v.valueKind()
  //  Returns true iff this value is equal to v, using a comparison
  //  appropriate to the kind of value.
{
  const NumericValue& vv = dynamic_cast<const NumericValue&>(v);
  return d == vv.d;
}
