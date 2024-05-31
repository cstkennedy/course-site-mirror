
class AuthorPosition {
public:
   AuthorPosition();

   // get data at this position
   Author getData() const;

   // get the position just after this one
   AuthorPosition next() const;

   // Is this the same position as pos?
   bool operator== (const AuthorPosition& pos) const;
   bool operator!= (const AuthorPosition& pos) const;

};
