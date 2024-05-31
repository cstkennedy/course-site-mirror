  public Value evaluateFormula()
  {
    Value newValue = (theFormula == null)
      ? new StringValue()
	: theFormula.evaluate(theSheet);

    if (theValue == null || !newValue.equals(theValue)) {
      theValue = newValue;
      setChanged();
      /*+1*/notifyObservers();/*-1*/
    }
    return theValue;
  }
