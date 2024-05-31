 class Student extends Comparable
 {
   String name;
   String id;
   double gpa;
   String school;
 
   boolean comesBefore(Object o)
   {
     return gpa > /*+1*/((Student)o)/*-1*/.gpa;
   }
 
 }
