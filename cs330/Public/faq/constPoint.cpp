class Point {
  int xcoord;
  int ycoord;
public:
  Point (int x, int y) :
    xcoord(x), yxoord(y)
  {}

  int& x() /*+1*/const/*-1*/ {return xcoord;}
  int& y() /*+1*/const/*-1*/ {return ycoord;}
};
