import java.io.*;

/**
 *   Demo of a program to read a line from a file 
 *   named on the command line.
 */
public class LineReader {
    
    /**
       Attempt to open a file
    */
    static void readFile (String fileName) 
    {
        boolean ok = false;
        while (!ok) {
            try {
                FileReader reader = new FileReader(fileName);
                BufferedReader in = new BufferedReader (reader);
                String line = in.readLine();
                System.out.println("First line is");
                System.out.println(line);
                ok = true;
            } catch (FileNotFoundException ex) {
                System.out.println ("Ouch: " + ex);
                
            } catch (IOException ex2) {
                System.out.println ("SOmething else " + ex2);
            }
        }
        
        /**
           Attempt to open the file whose name is given in
           the first command line parmaeter
        */
        public static void main (String[] argv) {
            String fileName = argv[0];
            readFile (fileName);
        }
    }
}
