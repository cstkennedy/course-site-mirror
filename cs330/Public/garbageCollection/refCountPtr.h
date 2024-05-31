template <class T>
class RefCountPointer {
  T* p;   /*1*/
  unsigned* count;

  void checkIfScavengable()  /*2*/
  {
    if (*count == 0)
      {
        delete count;
        delete p;
      }
  }

public:
  // This constructor is used to hand control of a newly
  // allocated object (*s) over to the reference count
  // system.  Example:
  //    RefCountPointer<PersonelRecord> p (new PersonelRecord());
  // It's critical that, once you create a reference counted
  // pointer to something, that you not continue playing with
  // regular pointers to the same object.
  RefCountPointer (T* s)   /*3*/
    : p(s), count(new unsigned)
    {*count = 1;} 

  RefCountPointer (const RefCountPointer& rcp)
    : p(rcp.p), count(rcp.count)
    {++(*count);}   /*4*/

  ~RefCountPointer() {--(*count); checkIfScavengable();} /*5*/
  

  RefCountPointer& operator= (const RefCountPointer& rcp)
    {
      ++(*(rcp.count));  /*6*/
      --(*count);
      checkIfScavengable();
      p = rcp.p;
      count = rcp.count;
      return *this;
    }

  T& operator*() const {return *p;}  /*7*/
  T* operator->() const {return p;}


  bool operator== (const RefCountPointer<T>& ptr) const
  {return ptr.p == p;}


  bool operator!= (const RefCountPointer<T>& ptr) const
  {return ptr.p != p;}

};
