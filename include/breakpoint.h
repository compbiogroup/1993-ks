/**********************************************************
 *
 * Author: Klairton L. Brito, klairton@ic.unicamp.br
 *
 **********************************************************/

#ifndef __AVOCADO_BREAKPOINT_H
#define __AVOCADO_BREAKPOINT_H

namespace avocado
{
	struct Breakpoint
	{
		int previous;
		int next;

		Breakpoint(int p, int n);
	};
}

#endif