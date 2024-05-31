myListOfStudents = ...;
 
 Sorting.insertionSort(myListOfStudents,
                       numStudents,
                       /*+*/new CompareByName()/*-*/);
 printStudentDirectory (myListOfStudents);
 
 Sorting.insertionSort(myListOfStudents,
                       numStudents,
                       /*+*/new CompareByGPA()/*-*/);
 printHonorsReport (myListOfStudents);
