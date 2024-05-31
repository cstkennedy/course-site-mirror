#ifndef BINARYEXPR_H
#define BINARYEXPR_H

#include "expression.h"


// Expressions with exactly two operands
class BinaryExpression: public Expression 
{
public:
  BinaryExpression (Expression* leftOperand,
		    Expression* rightOperand)
    : left(leftOperand), right(rightOperand) {}

  virtual ~BinaryExpression()  {delete left; delete right;}


  // How many operands does this expression node have?
  virtual unsigned arity() const    {return 2;}

  // Get the k_th operand
  virtual const Expression* operand(unsigned k) const
  //pre: k < arity()
    {return (k == 0) ? left : right;}



  // Evaluate this expression
  virtual Value* evaluate(const SpreadSheet&) const = 0;



  // Copy this expression (deep copy), altering any cell references
  // by the indicated offsets except where the row or column is "fixed"
  // by a preceding $. E.g., if e is  2*D4+C$2/$A$1, then
  // e.copy(1,2) is 2*E6+D$2/$A$1, e.copy(-1,4) is 2*C8+B$2/$A$1
  virtual Expression* clone (int colOffset, int rowOffset) const = 0;






  // The following control how the expression gets printed by 
  // the default implementation of put(ostream&)

  virtual bool isInline() const = 0;
  // if false, print as functionName(comma-separated-list)
  // if true, print in inline form

  virtual int precedence() const = 0;
  // Parentheses are placed around an expression whenever its precedence
  // is lower than the precedence of an operator (expression) applied to it.
  // E.g., * has higher precedence than +, so we print 3*(a1+1) but not
  // (3*a1)+1

  virtual std::string getOperator() const = 0;
  // Returns the name of the operator for printing purposes.
  // For constants, this is the string version of the constant value.


protected:
  Expression* left;
  Expression* right;
};



#endif


