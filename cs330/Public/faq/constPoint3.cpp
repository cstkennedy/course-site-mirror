class Point {
  int xcoord;
  int ycoord;
public:
  Point (int x, int y) :
    xcoord(x), yxoord(y)
  {}

  /*+1*/int& x() {return xcoord;}
  int x() const {return xcoord;}/*-1*/


  /*+1*/int& y() {return ycoord;}
  const int& y() const {return ycoord;}/*-1*/
};
