class Day
{
public:
  /*...*/
  void print(std::ostream out) const;
private:
  /*...*/
};

/*+1*/inline
std::ostream& operator<< (std::ostream& out, Day day)
{
  dat.print (out);
  return out;
}/*-1*/
