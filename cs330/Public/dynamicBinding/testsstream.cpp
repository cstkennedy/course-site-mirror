#include <iostream>
#include <sstream>
#include <string>

int main()
{
  ostringstream out;
  out << "Hello world! ";
  cout << "/" << out.str() << "/" << endl;
  out << 2+2;
  cout << "/" << out.str() << "/" << endl;
  return 0;
}
