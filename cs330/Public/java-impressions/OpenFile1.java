import java.io.*;

/**
   Demo of a program that may throw exceptions.
   @param argv The name of a file to open for input
*/
public class OpenFile1 {

  /**
     Attempt to open a file
  */
  static void openFile (String fileName) {
	FileReader reader = new FileReader(fileName);
  }
  
  /**
     Attempt to open the file whose name is given in
     the first command line parmaeter
  */
  public static void main (String[] argv) {
	String fileName = argv[1];
	openFile (fileName);
  }
}
