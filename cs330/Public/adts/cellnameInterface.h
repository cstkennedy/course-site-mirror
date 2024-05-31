
class CellName
{
public:
  CellName (std::string column, int row,
            bool fixTheColumn = false,
            bool fixTheRow=false);
  //pre: column.size() > 0 && all characters in column are alphabetic
  //     row > 0

  CellName (std::string cellname);
  //pre: exists j, 0<=j<cellname.size()-1, 
  //        cellname.substr(0,j) is all alphabetic (except for a
  //             possible cellname[0]=='$')
  //        && cellname.substr(j) is all numeric (except for a
  //             possible cellname[j]=='$') with at least one non-zero
  //             digit

  CellName (unsigned columnNumber = 0, unsigned rowNumber = 0,
            bool fixTheColumn = false,
            bool fixTheRow=false);

  std::string toString() const;
  // render the entire CellName as a string

  // Get components in spreadsheet notation
  std::string getColumn() const;
  int getRow() const;

  bool isRowFixed() const;
  bool isColumnFixed() const;


  // Get components as integer indices in range 0..
  int getColumnNumber() const;
  int getRowNumber() const;


  bool operator== (const CellName& r) const
     /*...*/
private:
     /*...*/
