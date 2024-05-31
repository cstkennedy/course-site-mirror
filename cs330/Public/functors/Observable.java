package java.util;

/**
 * This class represents an observable object, or "data"
 * in the model-view paradigm. 
 *
 * An observable object can have one or more observers. After an 
 * observable instance changes, an application calling the 
 * Observable's notifyObservers method  
 * causes all of its observers to be notified of the change by a call 
 * to their update method. 
 */
public class Observable {
    //\\vdots 

  public Observable() {/*{\ldots}*/}

    /**
     * Adds an observer to the set of observers for this object. 
     */
  public synchronized void addObserver(Observer o) {/*{\ldots}*/}

    /**
     * Deletes an observer from the set of observers of this object. 
     */
      public synchronized void deleteObserver(Observer o) {/*{\ldots}*/}

    /**
     * If this object has changed, as indicated by the 
     * hasChanged method, then notify all of its observers 
     * and then call the clearChanged method to 
     * indicate that this object has no longer changed. 
     */
  public void notifyObservers() {/*{\ldots}*/}
  public void notifyObservers(Object arg) {/*{\ldots}*/}

    /**
     * Clears the observer list so that this object no longer has any observers.
     */
  public synchronized void deleteObservers() {/*{\ldots}*/}

    /**
     * Indicates that this object has changed. 
     */
  protected synchronized void setChanged() {/*{\ldots}*/}

    /**
     * Indicates that this object has no longer changed, or that it has 
     * already notified all of its observers of its most recent change. 
     */
  protected synchronized void clearChanged() {/*{\ldots}*/}

    /**
     * Tests if this object has changed. 
     */
  public synchronized boolean hasChanged() {/*{\ldots}*/}

    /**
     * Returns the number of observers of this object.
     */
  public synchronized int countObservers() {/*{\ldots}*/}
}
