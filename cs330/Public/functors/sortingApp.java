 myListOfStudents = ...;
 
 /*+1*/CompareByName compareByName = new CompareByName();/*-1*/
 Sorting.insertionSort(myListOfStudents,
      numStudents, /*+2*/compareByName/*-2*/);
 printStudentDirectory (myListOfStudents);
 
 /*+1*/CompareByGPA compareByGPA = new CompareByGPA();/*-1*/
 Sorting.insertionSort(myListOfStudents,
      numStudents, /*+2*/compareByGPA/*-2*/);
 printHonorsReport (myListOfStudents);
