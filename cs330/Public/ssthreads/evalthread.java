class SpreadSheet
{


    class Evaluator extends Thread
    {
        public Evaluator() {}

        public void run() {
            while (true) {
                partialEvaluate();
            }
        }
    }

    public SpreadSheet()
    {
        theLowerRightCorner = new CellName("z", 26);
        evaluationCounter = 0;
        evaluationRequired = new Sequence();
        cells = new Hashtable();
        evaluator = new Evaluator();
        evaluator.start();
    }
