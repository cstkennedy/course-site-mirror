#ifndef OBSERVER_H
#define OBSERVER_H

//
// An Observer can register itself with any Observable object
// cell by calling the obervable's addObserver() function. Subsequently,
// the oberver wil be notified whenever the oberver calls its 
// notifyObservers() function (usually whenever the obervable object's
// value has changed.
//
// Notification occurs by calling the notify() function declared here.

class Observable;

class Observer
{
public:
  virtual void notify (Observable* changedObject) = 0;
};
#endif
