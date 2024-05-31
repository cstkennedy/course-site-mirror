
    // Cells use the following two functions to inform 
    // the spreadsheet of changes in their status

    synchronized void cellRequiresEvaluation (Cell c)
    {
        if (c.getValueIsCurrent())
            {
                c.putValueIsCurrent (false);
                evaluationRequired.addToBack (c);
                /*+1*/notifyAll();/*-1*/
            }
    }

    void cellHasNewFormula (Cell c)
    {
        evaluationCounter = 0;
        cellRequiresEvaluation(c);
    }


