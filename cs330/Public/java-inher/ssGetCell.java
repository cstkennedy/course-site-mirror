package SpreadSheetJ.Model;

import java.io.BufferedReader;
import java.io.Reader;
import java.io.Writer;

import java.util.Hashtable;
import java.util.Observer;


public
class SpreadSheet
{
  private CellName theLowerRightCorner;
  private Sequence evaluationRequired;
  private Hashtable cells;
  private int evaluationCounter;

  public SpreadSheet()
  {
	theLowerRightCorner = new CellName("z", 26);
	evaluationCounter = 0;
	evaluationRequired = new Sequence();
	cells = new Hashtable();
  }



  
  
  // Add and retrieve cells
  
  public SpreadSheetJ.Model.Cell getCell (CellName name)
  {
	Cell c = (Cell)cells.get(name);
	if (c == null) {
      c = new Cell(this, name);
      cells.put (name, c);
      evaluationCounter = 0;
      
      int columnNumber = name.getColumnNumber();
      int rowNumber = name.getRowNumber();
      if (columnNumber > theLowerRightCorner.getColumnNumber())
		resize (new CellName(columnNumber, 
                             theLowerRightCorner.getRowNumber()));
      if (rowNumber > theLowerRightCorner.getRowNumber())
		resize(new CellName(theLowerRightCorner.getColumnNumber(),
                            rowNumber));
	}
	return c;
  }      
