const Value* Cell::evaluateFormula()
{
  Value* newValue = (theFormula == 0)
    ? new StringValue()
    : /*+1*/theFormula->evaluate(theSheet)/*-1*/;

  if (theValue != 0 && /*+2*/*newValue == *theValue/*-2*/)
    delete newValue;
  else
    {
      /*+3*/delete theValue;
      theValue = newValue;
      notifyObservers();/*-3*/
    }
  return theValue;
}
