class ArraySet :
 public Set
{
public:
  ArraySet ();
  Set& add(int);
  bool member (int) const;   
  Set& clear();

private:
  int members[100];
  void copyMembers (Set& into) const;
};
