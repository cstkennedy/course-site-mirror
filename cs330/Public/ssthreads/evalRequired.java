public class SpreadSheet
{
      /*...*/
    private CellName theLowerRightCorner;
    /*+1*/private Sequence evaluationRequired;/*-1*/
    private Hashtable cells;
    private int evaluationCounter;

    static private final int EvaluationLimit = 100000;
    // Max number of of cell evaluations that can be undertaken as a result
    // of a change to any one cell. (Used to break off evaluation when
      /*...*/
