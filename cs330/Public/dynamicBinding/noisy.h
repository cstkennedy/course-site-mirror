#ifndef NOISY_H
#define NOISY_H

class Noisy 
{
  static int lastID;
  int id;
public:
  Noisy();
  Noisy(const Noisy&);
  virtual ~Noisy();

  void operator= (const Noisy&);
};

#endif
