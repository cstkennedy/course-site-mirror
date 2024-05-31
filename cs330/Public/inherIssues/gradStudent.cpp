class Person {
 public:
   string name;
   long id;
 };
 
 class Student: public Person {
 public:
   string school;
 }


class GraduateStudent: public Student {
private:
  /*+1*/Transcript* undergradRecords;/*-1*/
public:
   ...
   GraduateStudent (const GraduateStudent& g);
   GraduateStudent& operator= (const GradudateStudent&);
   ~GraduateStudent();
};

GraduateStudent::GraduateStudent (const GraduateStudent& g)
   : name(g.name), id(g.id), school(g.school),
     undergradRecords(new Transcript(*(g.undergradRecords))
{}

GraduateStudent& operator= (const GradudateStudent& g)
{
  if (this != &g)
    {
     Student::operator=(g);
     delete undergradRecords;
     undergradRecords = new Transcript(*(g.undergradRecords));
    }
   return *this;
}
   
/*+2*/GraduateStudent::~GraduateStudent() 
{
  delete undergradRecords;
}/*-2*/
