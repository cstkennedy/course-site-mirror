void Cell::notify (Observable* changedCell)
{
  theSheet.cellRequiresEvaluation (this);
}  
