/**********************************************************
 *
 * Author: Klairton L. Brito, klairton@ic.unicamp.br
 *
 **********************************************************/

#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <new>

#include "permutation.h"

avocado::Permutation::Permutation(int s)
{
  size = s;
  elements = new int [(s + 2)];
  elements[0] = 0;
  elements[s + 1] = s + 1;
}

avocado::Permutation::~Permutation()
{
  delete []elements;
}

avocado::Permutation* avocado::Permutation::Copy()
{
  avocado::Permutation *copy = new avocado::Permutation(size);
  std::memcpy(copy->elements, elements, (size + 2) * sizeof(int));
  return copy;
}

avocado::Permutation* avocado::Permutation::Inverse()
{
  avocado::Permutation *inverse = new avocado::Permutation(size);
  for (int i = 0; i <= (size + 1); i++)
  {
    inverse->elements[elements[i]] = i;
  }
  return inverse;
}

bool avocado::Permutation::IsIdentity()
{
  for (int i = 1; i <= size; i++)
  {
    if(i != elements[i]) return false;
  }
  return true;
}

std::vector<avocado::Breakpoint> avocado::Permutation::Breakpoints()
{
  std::vector<avocado::Breakpoint> breakpoints;
  breakpoints.reserve(size + 1);
  for (int i = 0; i <= size; i++)
  {
    if (abs(elements[i + 1] - elements[i]) != 1)
    {
      breakpoints.emplace_back(i, i + 1);
    }
  }
  return breakpoints;
}
