package SpreadSheetJ.Model;

import java.util.Observable;
import java.util.Observer;


// A single cell within a Spreadsheet
public
class Cell extends Observable implements Observer
{
  
  public Cell (SpreadSheet sheet, CellName name)
  {
    theSheet = sheet;
    theName = name;
    theFormula = null;
    theValue = null;
    outOfDate = false;
  }


  public CellName getName() 
  {
    return theName;
  }

  public Expression getFormula() 
  {
    return theFormula;
  }

  public void putFormula(Expression e)
  {
    if (theFormula != null)
    {
      Sequence oldReferences = theFormula.collectReferences();
      for (SearchEnumeration p = oldReferences.front();
       p.hasMoreElements(); ) {
    CellName cn = (CellName)p.nextElement();
    Cell c = theSheet.getCell(cn);
    c.deleteObserver (this);
      }
    }

    theFormula = e;
    if (e != null) 
      {
    Sequence newReferences = e.collectReferences();
    for (SearchEnumeration p = newReferences.front();
         p.hasMoreElements(); ) {
      CellName cn = (CellName)p.nextElement();
      Cell c = theSheet.getCell(cn);
      c.addObserver (this);
    }
      }
    theSheet.cellHasNewFormula (this);
  }

  public Value getValue() 
  {
    if (theValue == null)
      return defaultValue;
    else
      return theValue;
  }


  public Value evaluateFormula()
  {
    Value newValue = (theFormula == null)
      ? new StringValue()
    : theFormula.evaluate(theSheet);

    if (theValue == null || !newValue.equals(theValue)) {
      theValue = newValue;
      setChanged();
      notifyObservers();
    }
    return theValue;
  }



  public boolean getValueIsCurrent() 
  {
    return !outOfDate;
  }


  public void putValueIsCurrent(boolean isCurrent)
  {
    outOfDate = !isCurrent;
  }




  public void update (Observable changedCell, Object ignore)
  {
    //    System.err.println ("" + theName + " received notification about "
    //          + changedCell);
    theSheet.cellRequiresEvaluation (this);
  }  


  public String toString()
  {
    return theName.toString() + "::" + theFormula + "::" + theValue;
  }

  private SpreadSheet theSheet;
  private CellName theName;
  private Expression theFormula;
  private Value theValue;
  private boolean outOfDate;

  static private StringValue defaultValue = new StringValue("");

}
