class TreeSet: 
 public Set
{
public:
  TreeSet ();
  Set& add(int);
  bool member (int) const;   
  Set& clear();

private:
  PBinTreeNode root;
  void copyMembers (Set& into) const;
};
