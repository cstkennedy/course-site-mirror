
    // Cells use the following two functions to inform 
    // the spreadsheet of changes in their status

    void cellRequiresEvaluation (Cell c)
    {
        if (c.getValueIsCurrent())
            {
                c.putValueIsCurrent (false);
                evaluationRequired.addToBack (c);
            }
    }

    void cellHasNewFormula (Cell c)
    {
        evaluationCounter = 0;
        cellRequiresEvaluation(c);
    }


