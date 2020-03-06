/**********************************************************
 *
 * Author: Klairton L. Brito, klairton@ic.unicamp.br
 *
 **********************************************************/

#include <iostream>

#include "breakpoint.h"

avocado::Breakpoint::Breakpoint(int p, int n)
{
  previous = p;
  next = n;
}
