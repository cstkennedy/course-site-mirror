 class Student extends Person
               /*+1*/implements Comparable<Student>/*-1*/
 {
   double gpa;
   String school;
 
 /*+2*/  int compareTo(Object o)
   {
     Student s = (Student)o;
     if (gpa < s.gpa)
       return -1;
     else if (gpa == s.gpa)
       return 0;
     else
       return 1;
   }
/*-2*/}
