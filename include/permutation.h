/**********************************************************
 *
 * Author: Klairton L. Brito, klairton@ic.unicamp.br
 *
 **********************************************************/

#ifndef __AVOCADO_PERMUTATION_H
#define __AVOCADO_PERMUTATION_H

#include <iostream>
#include <vector>

#include "breakpoint.h"

namespace avocado
{
	class Permutation
	{
		public:
			int size;
			int *elements;

			Permutation(int s);
			~Permutation();
			Permutation* Copy();
			Permutation* Inverse();
			bool IsIdentity();
			std::vector<avocado::Breakpoint> Breakpoints();
			friend std::ostream& operator << (std::ostream &stream, const Permutation& pi)
			{
			  for(int i = 1; i <= pi.size; i++) {
			    (i == 1) ? stream <<  pi.elements[i] : stream << "," << pi.elements[i];
			  }
			  return stream; 
			}
	};
}

#endif