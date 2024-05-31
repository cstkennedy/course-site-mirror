
class AuthorPosition {
public:
   AuthorPosition();

   // get data at this position
   Author operator*() const;

   // get a data/function member at this position
   Author* operator->() const;

   // move forward to the position just after this one
   AuthorPosition operator++();

   // Is this the same position as pos?
   bool operator== (const AuthorPosition& pos) const;
   bool operator!= (const AuthorPosition& pos) const;

};
