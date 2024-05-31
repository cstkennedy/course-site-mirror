const Value* Cell::evaluateFormula()
{
  Value* newValue = (theFormula == 0)
    ? new StringValue()
    : theFormula->evaluate(theSheet);

  if (theValue != 0 && *newValue == *theValue)
    delete newValue;
  else
    {
      delete theValue;
      theValue = newValue;
      notifyObservers();
    }
  return theValue;
}
