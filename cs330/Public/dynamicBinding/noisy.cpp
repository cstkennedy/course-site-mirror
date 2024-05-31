#include "noisy.h"
#include <iostream>

using namespace std;

int Noisy::lastID = 0;

Noisy::Noisy()
{
  id = lastID++;
  cerr << "Created object " << id << endl;
}

Noisy::Noisy(const Noisy& x)
{
  id = lastID++;
  cerr << "Copied object " << id << " from object " << x.id << endl;
}

Noisy::~Noisy()
{
  cerr << "Destroyed object " << id << endl;
}
  

void Noisy::operator= (const Noisy&) {}

