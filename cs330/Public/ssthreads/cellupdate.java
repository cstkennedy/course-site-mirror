  public void update (Observable changedCell, Object ignore)
  {
    //    System.err.println ("" + theName + " received notification about "
    //			+ changedCell);
    theSheet.cellRequiresEvaluation (this);
  }  
