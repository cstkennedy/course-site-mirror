    // Remove c from the observer list of the cell at position cname
    public synchronized void deleteCellObserver (CellName cname, Observer c)
    {
        Cell observer = getCell(cname);
        observer.deleteObserver(c);
    }


    // Add c as an observer of the cell at position cname
    public synchronized void addCellObserver (CellName cname, Observer c)
    {
        Cell observer = getCell(cname);
        observer.addObserver(c);
    }


    // Get the formula associated with the cell at position cname
    public synchronized Expression getFormula(CellName cname) 
    {
        return getCell(cname).getFormula();
    }


    // Put a formula into the cell at position cname
