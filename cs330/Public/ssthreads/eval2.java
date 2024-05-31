    // Re-evaluate all cells in the spreadsheet
    public int evaluateAll()
    {
        return 1;
    } 

    // Evaluate one or more cells in the spreadsheet
    synchronized void partialEvaluate()
    {
        if (moreToEvaluate()) {
            Cell c = (Cell)evaluationRequired.front().at();
            evaluationRequired.removeFront();
            c.putValueIsCurrent (true);
            
            ++evaluationCounter;
            c.evaluateFormula();
        } else {
            /*+1*/try {
                wait();
            } catch (InterruptedException ex) {}/*-1*/
        }
    }

    // Return true if at least one cell is believed to require evaluation
    public boolean moreToEvaluate()
    {
        return (evaluationRequired.size() > 0
                && evaluationCounter < EvaluationLimit);
    }


