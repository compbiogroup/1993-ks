/**********************************************************
 *
 * Author: Klairton L. Brito, klairton@ic.unicamp.br
 *
 **********************************************************/

#include <iostream>

#include "breakpoint.h"
#include "reversal.h"
#include "permutation.h"
#include "events.h"
#include "algorithm.h"

int main () {
  avocado::Permutation *pi = new avocado::Permutation(5);
  pi->elements[1] = 3;
  pi->elements[2] = 1;
  pi->elements[3] = 5;
  pi->elements[4] = 2;
  pi->elements[5] = 4;

  std::cout << *pi << std::endl;

  avocado::Algorithm algorithm;
  std::vector<avocado::Reversal> sequence = algorithm.Run(pi);
  delete pi;

  std::cout << "[";
  for (int i = 0; i < sequence.size(); i++)
  {
    (i == 0) ? std::cout << sequence[i] : std::cout << "," << sequence[i];
  }
  std::cout << "]";
  std::cout << std::endl;

  sequence.clear();

  return 0;
}