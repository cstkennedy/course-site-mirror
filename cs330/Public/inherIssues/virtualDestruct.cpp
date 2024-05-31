class Person {
 public:
   /*+1*/virtual ~Person() {}/*-1*/
   string name;
   long id;
 };
 
 class Student: public Person {
 public:
   string school;
 }


class GraduateStudent: public Student {
private:
   Transcript* undergradRecords;
public:
    /*...*/
   GraduateStudent (const GraduateStudent& g);
   GraduateStudent& operator= (const GradudateStudent&);
   ~GraduateStudent();
};
