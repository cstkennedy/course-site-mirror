void Cell::putFormula(Expression* e)
{
  if (theFormula != 0)  
    {  /*1*/
      CellNameSequence oldReferences = theFormula->collectReferences();
      for (CellNameSequence::Position p = oldReferences.front();
           p != 0; p = oldReferences.getNext(p))
        {
          Cell* c = theSheet.getCell(oldReferences.at(p));
          if (c != 0)
            c->removeObserver (this);
        }
      delete theFormula;
    }
  theFormula = e; /*2*/
  if (e != 0) 
    {     /*3*/
      CellNameSequence newReferences = e->collectReferences();
      for (CellNameSequence::Position p = newReferences.front();
           p != 0; p = newReferences.getNext(p))
        {
          Cell* c = theSheet.getCell(newReferences.at(p));
          if (c != 0)
            c->addObserver (this);
        }
    }
  theSheet.cellHasNewFormula (this); /*4*/
}
