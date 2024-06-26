class Person {
 public:
   virtual ~Person() {}
   virtual Person& operator= (const Person& p);
   string name;
   long id;
 };
 
 class Student: public Person {
 public:
   string school;
   virtual Person& operator= (const Person& p); // inherited from Person
   // Student& operator= (const Student& s); // generated by compiler
 }


class GraduateStudent: public Student {
private:
   Transcript* undergradRecords;
public:
   ...
   GraduateStudent (const GraduateStudent& g);
   virtual Person& operator= (const Person& p); // inherited from Person
   // Student& operator= (const Student& s); // inherited from Student
   GraduateStudent& operator= (const GradudateStudent&);
   ~GraduateStudent();
};
