#include "counted.h"
#include <iostream>

using namespace std;

int Counted::numCreated = 0;
int Counted::numDestroyed = 0;

Counted::Counted()
{
  ++numCreated;
}

Counted::Counted(const Counted& x)
{
  ++numCreated;
}

Counted::~Counted()
{
  ++numDestroyed;
}
  


void Counted::report()
{
  cerr << "Created " << numCreated << " objects." << endl;
  cerr << "Destroyed " << numDestroyed << " objects." << endl;
}



