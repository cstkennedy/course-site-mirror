#ifndef CELLEXPR_H
#define CELLEXPR_H

#include "expression.h"
#include "cellname.h"


class CellReferenceNode: public Expression
{
private:
  CellName value;

public:
  CellReferenceNode () {}
  CellReferenceNode (CellName name): value(name) {}

  // How many operands does this expression node have?
  virtual unsigned arity() const {return 0;}

  // Get the k_th operand
  virtual const Expression* operand(unsigned k) const;
  //pre: k < arity()




  // Evaluate this expression
  virtual Value* evaluate(const SpreadSheet&) const;



  // Copy this expression (deep copy), altering any cell references
  // by the indicated offsets except where the row or column is "fixed"
  // by a preceding $. E.g., if e is  2*D4+C$2/$A$1, then
  // e.copy(1,2) is 2*E6+D$2/$A$1, e.copy(-1,4) is 2*C8+B$2/$A$1
  virtual Expression* clone (int colOffset, int rowOffset) const;



  // The following control how the expression gets printed by 
  // the default implementation of put(ostream&)

  virtual bool isInline() const;
  // if false, print as functionName(comma-separated-list)
  // if true, print in inline form

  virtual int precedence() const {return 1000;}
  // Parentheses are placed around an expression whenever its precedence
  // is lower than the precedence of an operator (expression) applied to it.
  // E.g., * has higher precedence than +, so we print 3*(a1+1) but not
  // (3*a1)+1

  virtual string getOperator() const;
  // Returns the name of the operator for printing purposes.
  // For constants, this is the string version of the constant value.


  virtual CellNameSequence collectReferences() const;

};

#endif
