/**********************************************************
 *
 * Author: Klairton L. Brito, klairton@ic.unicamp.br
 *
 **********************************************************/

#include <iostream>

#include "events.h"

void avocado::reversal(int i, int j, avocado::Permutation *pi)
{
  if(i < j)
  {
  	SWAP(pi->elements[i], pi->elements[j], int);
  	avocado::reversal((i + 1), (j - 1), pi);
  }
}