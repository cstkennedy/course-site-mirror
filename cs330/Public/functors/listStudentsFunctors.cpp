 class StudentSelectors {
 public:
    bool /*+*/operator()/*-*/ (const Student&) const =0;
 };
 
 void listSelectedStudents
       (Student[] students,
        int nStudents,
        StudentSelectors selector)
 {
   for (int i = 0; i < nStudents; ++i)
      if (/*+1*/selector(/*-1*/students[i]/*+1*/)/*-1*/)
         cout << students[i] << endl;
 }
