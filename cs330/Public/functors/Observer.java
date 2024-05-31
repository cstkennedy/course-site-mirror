package java.util;

public interface Observer {

  public abstract void 
    update(Observable o,
	   Object arg);
  /*
   This method is called whenever the observed 
   object is changed.
  */
}
