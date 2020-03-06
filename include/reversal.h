/**********************************************************
 *
 * Author: Klairton L. Brito, klairton@ic.unicamp.br
 *
 **********************************************************/

#ifndef __AVOCADO_REVERSAL_H
#define __AVOCADO_REVERSAL_H

namespace avocado
{
  struct Reversal
  {
    int i;
    int j;

    Reversal(int i, int j);

    friend std::ostream& operator << (std::ostream &stream, const Reversal& rev)
    {
      stream <<  "(" << rev.i << "," << rev.j << ")";
      return stream; 
    }
  };
}

#endif