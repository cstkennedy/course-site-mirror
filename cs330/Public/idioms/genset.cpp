void generateSet (int numElements, Set& s, int *expected)
{
  int elements[MaxSetElement];
  

  for (int i = 0; i < MaxSetElement; i++)
    {
      elements[i] = i;
      expected[i] = 0;
    }
  

  // Now scramble the ordering of the elements array
  for (i = 0; i < MaxSetElement; i++)
    {
      int j = rand(MaxSetElement);
      int t = elements[i];
      elements[i] = elements[j];
      elements[j] = t;
    }

  // Insert the first numElements values into s
  s.clear();
  for (i = 0; i < numElements; i++)
    {
      s.add(elements[i]);
      expected[elements[i]] = 1;
    }
}
