void copyFile (string fileName)
{
   ifstream input (fileName/*+1*/.c_str()/*-1*/); // open an input file;
   ofstream output ("output.txt"); // No c_str() required - "output.txt" is a
                                   //    character array, not a string.
   string line;
   getline (input, line);
   while (input) 
   {
      output << line << endl;
      getline (input, line);
   }   
}
