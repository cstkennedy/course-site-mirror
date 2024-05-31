 class StudentSelectors {
 public:
    bool test(const Student&) const =0;
 };
 
 void listSelectedStudents
       (Student[] students,
        int nStudents,
        StudentSelectors selector)
 {
   for (int i = 0; i < nStudents; ++i)
      if (/*+1*/selector.test/*-1*/(students[i]))
         cout << students[i] << endl;
 }
