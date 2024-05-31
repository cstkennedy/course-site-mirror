#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "observerptrseq.h"

// An Observable object allows any number of Observers to register
// with it. When a significant change has occured to the Observable object, 
// it calls notifyObservers() and each registered observer will be notified.
// (See also oberver.h)

class Observer;

class Observable
{
public:

  // Add and remove observers
  void addObserver (Observer* observer);
  void removeObserver (Observer* observer);

  //   For each registered Observer, call notify(this)
  void notifyObservers();

private:
  ObserverPtrSequence observers;
};


#endif
