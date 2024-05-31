public
class SpreadSheet
{
    <[:]>
    private Cell getCell (CellName name)
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
    <[:]>
