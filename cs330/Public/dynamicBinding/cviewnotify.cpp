  CellRange visiblePortion = showing();
  for (CellName cn = visiblePortion.first(); visiblePortion.more(cn);
       cn = visiblePortion.next(cn))
    {
	Cell* c = sheet.putCell(cn);
	c->addObserver(this);
    }
}


void NCursesSpreadSheetView::notify (Observable* changedCell)
{
  Cell* c = (Cell*)changedCell;
  drawCell(c->getName());
}
