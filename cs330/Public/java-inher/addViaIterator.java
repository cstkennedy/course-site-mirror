 LinkedList<Book> books = new LinkedList<Book>();
 books.add(cs330Text);
 books.add(cs361Text);
 books.add(cs252Text);
   <:\smvdots:>
 boolean found = false;
 /*+1*/ListIterator<Book>/*-1*/ it = books./*+1*/listIterator()/*-1*/;
 while (it.hasNext() && !found)
 {
   Book b = (Book)it.next();
   found = (b.equals(cs252Text);
 }
 if (found)
 {
   it.remove();
 }
 /*+1*/it.add(cs252textVersion2);/*-1*/
