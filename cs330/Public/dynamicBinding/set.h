class Set 
{
public:
  Set ();
  Set (const Set&);
  virtual ~Set ();
  const Set& operator= (const Set&);

  virtual Set& add(int);
  virtual bool member (int) const;   
  virtual Set& clear();
  int extent () const;

protected:
  int size;  
  virtual void copyMembers (Set& into) const;
};
