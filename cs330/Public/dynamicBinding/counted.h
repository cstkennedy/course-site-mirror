#ifndef COUNTED_H
#define COUNTED_H

class Counted 
{
  static int numCreated;
  static int numDestroyed;
public:
  Counted();
  Counted(const Counted&);
  virtual ~Counted();

  static void report();

};

#endif
