#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <iostream>

#include "cellnameseq.h"

class SpreadSheet;
class Value;

// Expressions can be thought of as trees.  Each non-leaf node of the tree
// contains an operator, and the children of that node are the subexpressions
// (operands) that the operator operates upon.  Constants, cell references,
// and the like form the leaves of the tree.
// 
// For example, the expression (a2 + 2) * c26 is equivalent to the tree:
// 
//                *
//               / \
//              +   c26
//             / \
//           a2   2

class Expression 
{
public:

  virtual ~Expression() {}


  // How many operands does this expression node have?
  virtual unsigned arity() const = 0;

  // Get the k_th operand
  virtual const Expression* operand(unsigned k) const = 0;
  //pre: k < arity()




  // Evaluate this expression
  virtual Value* evaluate(const SpreadSheet&) const = 0;



  // Copy this expression (deep copy), altering any cell references
  // by the indicated offsets except where the row or column is "fixed"
  // by a preceding $. E.g., if e is  2*D4+C$2/$A$1, then
  // e.copy(1,2) is 2*E6+D$2/$A$1, e.copy(-1,4) is 2*C8+B$2/$A$1
  virtual Expression* clone (int colOffset, int rowOffset) const = 0;



  virtual CellNameSequence collectReferences() const;


  static Expression* get (std::istream& in, char terminator);
  static Expression* get (const std::string& in);
  virtual void put (std::ostream& out) const;



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

  virtual string getOperator() const = 0;
  // Returns the name of the operator for printing purposes.
  // For constants, this is the string version of the constant value.



};



inline std::istream& operator>> (std::istream& in, Expression*& e)
{
  string line;
  getline(in, line);
  e = Expression::get (line);
  return in;
}


inline std::ostream& operator<< (std::ostream& out, const Expression& e)
{
  e.put (out);
  return out;
}

inline std::ostream& operator<< (std::ostream& out, const Expression* e)
{
  e->put (out);
  return out;
}

#endif
