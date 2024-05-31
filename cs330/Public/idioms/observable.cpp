#include "observable.h"
#include "observer.h"


// An Observable object allows any number of Observers to register
// with it. When a significant change has occured to the Observable object, 
// it calls notifyObservers() and each registered observer will be notified.
//

// Add and remove observers
void Observable::addObserver (Observer* observer)
{
  observers.addToFront (observer);
}


void Observable::removeObserver (Observer* observer)
{
  ObserverPtrSequence::Position p = observers.find(observer);
  if (p != 0)
    observers.remove(p);
}

//   For each registered Observer, call hasChanged(this)
void Observable::notifyObservers()
{
  for (ObserverPtrSequence::Position p = observers.front();
       p != 0; p = observers.getNext(p))
    {
      observers.at(p)->notify(this);
    }
}
