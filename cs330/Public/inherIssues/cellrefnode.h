 class CellReferenceNode: public Expression
 { // represents a reference to a cell
 private:
   CellName value;
 
 public:
   CellReferenceNode () {}
     <:\smvdots:>
 
 // Evaluate this expression
   virtual Value* evaluate(const SpreadSheet&) const;
     <:\smvdots:>
