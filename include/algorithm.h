/**********************************************************
 *
 * Author: Klairton L. Brito, klairton@ic.unicamp.br
 *
 **********************************************************/

#ifndef __AVOCADO_ALGORITHM_H
#define __AVOCADO_ALGORITHM_H

#include <iostream>
#include <vector>

#include "permutation.h"
#include "reversal.h"

namespace avocado
{
	class Algorithm
	{
		private:
			bool AnyDecreasingStrip(avocado::Permutation *pi);
			int SmallestElementInAllDecreasingStrips(avocado::Permutation *pi);
			int LargestElementInAllDecreasingStrips(avocado::Permutation *pi);
		public:
			std::vector<avocado::Reversal> Run(avocado::Permutation *pi);
	};
}

#endif