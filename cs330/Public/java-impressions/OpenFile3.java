import java.io.*;

/**
   Demo of a program that may throw exceptions.
   @param argv The name of a file to open for input
*/
public class OpenFile3 {
  
  /**
     Attempt to open a file
  */
  static void openFile (String fileName)
	throws java.io.FileNotFoundException
  {
	FileReader reader = new FileReader(fileName);
  }
  
  /**
     Attempt to open the file whose name is given in
     the first command line parmaeter
  */
  public static void main (String[] argv) {
      try {
	  openFile (argv[0]);
      }
      catch (java.io.FileNotFoundException ex)
	  {
	      System.err.println ("Something is wrong with the file: " + ex);
	  }
      System.out.println ("All done");
  }
}
