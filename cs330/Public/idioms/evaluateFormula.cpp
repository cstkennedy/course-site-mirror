const Value* Cell::evaluateFormula()
{
  Value* newValue = (theFormula == 0)
    ? new StringValue()
    : theFormula->evaluate(theSheet);   /*1*/

  if (theValue != 0 && *newValue == *theValue) /*2*/
    delete newValue;    /*3*/
  else
    {    /*4*/
      delete theValue;
      theValue = newValue;
      notifyObservers();   /*5*/
    }
  return theValue;
}
