bool StringValue::isEqual (const Value& v) const
  //pre: valueKind() == v.valueKind()
  //  Returns true iff this value is equal to v, using a comparison
  //  appropriate to the kind of value.
{
  const StringValue& vv = dynamic_cast<const StringValue&>(v);
  return s == vv.s;
}
