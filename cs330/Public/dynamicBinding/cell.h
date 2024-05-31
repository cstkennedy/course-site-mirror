#ifndef CELL_H
#define CELL_H

#include "cellname.h"
#include "observable.h"
#include "observer.h"
#include "strvalue.h"

class Expression;
class Value;
class SpreadSheet;


// A single cell within a Spreadsheet
class Cell: public Observable, Observer
{
public:
  Cell (SpreadSheet& sheet, CellName name);
  Cell(const Cell&);

  ~Cell();

  CellName getName() const;

  const Expression* getFormula() const;
  void putFormula(Expression*);

  const Value* getValue() const;
  const Value* evaluateFormula();

  bool getValueIsCurrent() const;
  void putValueIsCurrent(bool);


  virtual void notify (Observable* changedCell);

private:
  SpreadSheet& theSheet;
  CellName theName;
  Expression* theFormula;
  Value* theValue;
  bool outOfDate;
  static StringValue defaultValue;
};

#endif
