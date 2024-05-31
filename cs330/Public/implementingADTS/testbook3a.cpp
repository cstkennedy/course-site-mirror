#include <algorithm>
#include <iostream>
#include <string>

#include "unittest.h"

#include "book3a.h"


using namespace std;

void testSimpleConstructor();
void testArrayBasedConstructor();
void testTitle();
void testISBN();
void testPublisher();
void testAddAuthor();
void testRemoveAuthor();

void runSuite()
{
  testSimpleConstructor();
  testArrayBasedConstructor();
  testTitle();
  testISBN();
  testPublisher();
  testAddAuthor();
  testRemoveAuthor();
}




int main ()
{
  runSuite();
  UnitTest::report(cerr);
}


void testSimpleConstructor()
{
  Author au ("J. Doe");
  Book b (au);
  
  assertEqual(b.getNumberOfAuthors(), 1);
  assertEqual(*(b.begin()), au);
  
  assertEqual (b.getTitle(), "");
  assertEqual (b.getISBN(), "");
  Publisher pub;
  assertEqual (b.getPublisher(), pub);
}

void testArrayBasedConstructor()
{
  const Author au1 ("J. Doe");
  const Author au2 ("S. Jones");
  const Author au3 ("M. Smith");
  const Author authors[] = {au1, au2, au3}; 
  
  {
    Book b (authors, 3);
    
    assertEqual(b.getNumberOfAuthors(), 3);
    assertTrue (std::equal(b.begin(), b.end(), authors));
    
    assertEqual (b.getTitle(), "");
    assertEqual (b.getISBN(), "");
    Publisher pub;
    assertEqual (b.getPublisher(), pub);
  }
  
  {
    Book b (authors, 1);
    
    assertEqual(b.getNumberOfAuthors(), 1);
    assertTrue (std::equal(b.begin(), b.end(), authors));
    
    assertEqual (b.getTitle(), "");
    assertEqual (b.getISBN(), "");
    Publisher pub;
    assertEqual (b.getPublisher(), pub);
  }
  
  {
    Book b (authors, 0);
    
    assertEqual(b.getNumberOfAuthors(), 0);
    assertEqual (b.begin(), b.end());
    
    assertEqual (b.getTitle(), "");
    assertEqual (b.getISBN(), "");
    Publisher pub;
    assertEqual (b.getPublisher(), pub);
  }
}

void testTitle()
{
  const Author au1 ("J. Doe");
  Book b (au1);
  
  assertEqual (b.getTitle(), "");
  string newTitle ("Fun with C++");
  b.setTitle (newTitle);
  assertEqual (b.getTitle(), newTitle);
}

void testISBN()
{
  const Author au1 ("J. Doe");
  Book b (au1);
  
  assertEqual (b.getTitle(), "");
  string newISBN ("01234-56789");
  b.setISBN (newISBN);
  assertEqual (b.getISBN(), newISBN);
}

void testPublisher()
{
  const Author au1 ("J. Doe");
  Book b (au1);
  
  assertEqual (b.getTitle(), "");
  Publisher newPublisher ("Vanity Press");
  b.setPublisher (newPublisher);
  assertEqual (b.getPublisher(), newPublisher);
}

void testAddAuthor()
{
  const Author au1 ("J. Doe");
  const Author au2 ("S. Jones");
  const Author au3 ("M. Smith");
  const Author au4 ("J. Johnson");
  Author authors[] = {au1, au2, au3}; 
  
  Book b (authors, 3);
  string newTitle ("Fun with C++");
  b.setTitle (newTitle);
  string newISBN ("01234-56789");
  b.setISBN (newISBN);
  Publisher newPublisher ("Vanity Press");
  b.setPublisher (newPublisher);
  
  {
    Book b2 = b;
    b2.addAuthor (b2.begin(), au4);
    assertEqual(b2.getNumberOfAuthors(), b.getNumberOfAuthors()+1);
    Author expected[] = {au4, au1, au2, au3};
    assertTrue (std::equal(b2.begin(), b2.end(), expected));
    
    assertEqual (b.getTitle(), b2.getTitle());
    assertEqual (b.getISBN(), b2.getISBN());
    assertEqual (b.getPublisher(), b2.getPublisher());
  }
  
  {
    Book b2 = b;
    b2.addAuthor (b2.end(), au4);
    assertEqual(b2.getNumberOfAuthors(), b.getNumberOfAuthors()+1);
    Author expected[] = {au1, au2, au3, au4};
    assertTrue (std::equal(b2.begin(), b2.end(), expected));
    
    assertEqual (b.getTitle(), b2.getTitle());
    assertEqual (b.getISBN(), b2.getISBN());
    assertEqual (b.getPublisher(), b2.getPublisher());
  }
  
  {
    Book b2 = b;
    Book::AuthorPosition pos = b2.begin();
    ++pos;
    b2.addAuthor (pos, au4);
    assertEqual(b2.getNumberOfAuthors(), b.getNumberOfAuthors()+1);
    Author expected[] = {au1, au4, au2, au3};
    assertTrue (std::equal(b2.begin(), b2.end(), expected));
    
    assertEqual (b.getTitle(), b2.getTitle());
    assertEqual (b.getISBN(), b2.getISBN());
    assertEqual (b.getPublisher(), b2.getPublisher());
  }
  
  {
    Book b3 (authors, 0);
    Book b2 = b3;
    b2.addAuthor (b2.begin(), au4);
    assertEqual(b2.getNumberOfAuthors(), b3.getNumberOfAuthors()+1);
    Author expected[] = {au4};
    assertTrue (std::equal(b2.begin(), b2.end(), expected));
    
    assertEqual (b3.getTitle(), b2.getTitle());
    assertEqual (b3.getISBN(), b2.getISBN());
    assertEqual (b3.getPublisher(), b2.getPublisher());
  }
}


void testRemoveAuthor()
{
  const Author au1 ("J. Doe");
  const Author au2 ("S. Jones");
  const Author au3 ("M. Smith");
  Author authors[] = {au1, au2, au3}; 
  
  Book b (authors, 3);
  string newTitle ("Fun with C++");
  b.setTitle (newTitle);
  string newISBN ("01234-56789");
  b.setISBN (newISBN);
  Publisher newPublisher ("Vanity Press");
  b.setPublisher (newPublisher);
  
  {
    Book b2 = b;
    b2.removeAuthor (b2.begin());
    assertEqual(b2.getNumberOfAuthors(), b.getNumberOfAuthors()-1);
    Author expected[] = {au2, au3};
    assertTrue (std::equal(b2.begin(), b2.end(), expected));
    
    assertEqual (b.getTitle(), b2.getTitle());
    assertEqual (b.getISBN(), b2.getISBN());
    assertEqual (b.getPublisher(), b2.getPublisher());
  }
  
  {
    Book b2 = b;
    Book::AuthorPosition pos = b2.begin();
    ++pos;
    b2.removeAuthor (pos);
    assertEqual(b2.getNumberOfAuthors(), b.getNumberOfAuthors()-1);
    Author expected[] = {au1, au3};
    assertTrue (std::equal(b2.begin(), b2.end(), expected));
    
    assertEqual (b.getTitle(), b2.getTitle());
    assertEqual (b.getISBN(), b2.getISBN());
    assertEqual (b.getPublisher(), b2.getPublisher());
  }
  
  {
    Book b2 = b;
    Book::AuthorPosition pos = b2.begin();
    ++pos;
    ++pos;
    b2.removeAuthor (pos);
    assertEqual(b2.getNumberOfAuthors(), b.getNumberOfAuthors()-1);
    Author expected[] = {au1, au2};
    assertTrue (std::equal(b2.begin(), b2.end(), expected));
    
    assertEqual (b.getTitle(), b2.getTitle());
    assertEqual (b.getISBN(), b2.getISBN());
    assertEqual (b.getPublisher(), b2.getPublisher());
  }
  
  {
    Book b3 (au1);
    Book b2 = b3;
    b2.removeAuthor (b2.begin());
    assertEqual(b2.getNumberOfAuthors(), b3.getNumberOfAuthors()-1);
    
    assertEqual (b3.getTitle(), b2.getTitle());
    assertEqual (b3.getISBN(), b2.getISBN());
    assertEqual (b3.getPublisher(), b2.getPublisher());
  }
}
