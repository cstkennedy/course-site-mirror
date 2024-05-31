public
class Cell extends Observable implements Observer
{
  
    /*...*/
  public void putFormula(Expression e)
  {
    if (theFormula != null)
    {
      Sequence oldReferences = theFormula.collectReferences();
      for (SearchEnumeration p = oldReferences.front();
	   p.hasMoreElements(); ) {
	CellName cn = (CellName)p.nextElement();
	theSheet.deleteCellObserver (cn,this);
      }
    }

    theFormula = e;
    if (e != null) 
      {
	Sequence newReferences = e.collectReferences();
	for (SearchEnumeration p = newReferences.front();
	     p.hasMoreElements(); ) {
	  CellName cn = (CellName)p.nextElement();
	  theSheet.addCellObserver(cn, this);
	}
      }
    theSheet.cellHasNewFormula (this);
  }
    /*...*/
