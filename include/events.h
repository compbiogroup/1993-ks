/**********************************************************
 *
 * Author: Klairton L. Brito, klairton@ic.unicamp.br
 *
 **********************************************************/

#ifndef __AVOCADO_EVENTS_H
#define __AVOCADO_EVENTS_H
#define SWAP(x, y, T) { T SWAP = x; x = y; y = SWAP; }

#include "permutation.h"

namespace avocado
{
  void reversal(int i, int j, avocado::Permutation *pi);
}

#endif
