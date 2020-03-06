/**********************************************************
 *
 * Author: Klairton L. Brito, klairton@ic.unicamp.br
 *
 **********************************************************/

#include <iostream>
#include <vector>

#include "algorithm.h"
#include "breakpoint.h"
#include "events.h"

bool avocado::Algorithm::AnyDecreasingStrip(avocado::Permutation *pi)
{
	std::vector<avocado::Breakpoint> breakpoints = pi->Breakpoints();
	for (int i = 0; i < breakpoints.size() - 1; i++)
	{
		if (pi->elements[breakpoints[i].next] >= pi->elements[breakpoints[i + 1].previous])
		{
			return true;
		}
	}

	breakpoints.clear();
	return false;
}

int avocado::Algorithm::SmallestElementInAllDecreasingStrips(avocado::Permutation *pi) {
	std::vector<avocado::Breakpoint> breakpoints = pi->Breakpoints();
	int smallest_element = pi->size + 1;

	for (int i = 0; i < breakpoints.size() - 1; i++)
	{
		if (pi->elements[breakpoints[i].next] >= pi->elements[breakpoints[i + 1].previous])
		{
			if (smallest_element > pi->elements[breakpoints[i + 1].previous])
			{
				smallest_element = pi->elements[breakpoints[i + 1].previous];
			}
		}
	}

	breakpoints.clear();
	return smallest_element;
}

int avocado::Algorithm::LargestElementInAllDecreasingStrips(avocado::Permutation *pi)
{
	std::vector<avocado::Breakpoint> breakpoints = pi->Breakpoints();
	int largest_element = 0;

	for (int i = 0; i < breakpoints.size() - 1; i++)
	{
		if (pi->elements[breakpoints[i].next] >= pi->elements[breakpoints[i + 1].previous])
		{
			if (largest_element < pi->elements[breakpoints[i].next])
			{
				largest_element = pi->elements[breakpoints[i].next];
			}
		}
	}

	breakpoints.clear();
	return largest_element;
}

std::vector<avocado::Reversal> avocado::Algorithm::Run(avocado::Permutation *pi)
{
	std::vector<avocado::Reversal> sequence;
	avocado::Permutation *inverse = NULL;
	int l, s, i, j;

	while(!pi->IsIdentity())
	{
		if (AnyDecreasingStrip(pi))
		{
			s = SmallestElementInAllDecreasingStrips(pi);
			inverse = pi->Inverse();
			i = inverse->elements[s];
			j = inverse->elements[s - 1];
			(i < j) ? avocado::reversal(i + 1, j, pi) : avocado::reversal(j + 1, i, pi);

			if (!AnyDecreasingStrip(pi))
			{
				(i < j) ? avocado::reversal(i + 1, j, pi) : avocado::reversal(j + 1, i, pi);
				l = LargestElementInAllDecreasingStrips(pi);
				i = inverse->elements[l];
				j = inverse->elements[l + 1];
				(i < j) ? avocado::reversal(i, j - 1, pi) : avocado::reversal(j + 1, i, pi);
				(i < j) ? sequence.emplace_back(i, j - 1) : sequence.emplace_back(j + 1, i);
			}
			else
			{
				(i < j) ? sequence.emplace_back(i + 1, j) : sequence.emplace_back(j + 1, i);
			}
			delete inverse;
		}
		else
		{
			std::vector<avocado::Breakpoint> breakpoints = pi->Breakpoints();
			i = breakpoints[0].next;
			j = breakpoints[1].previous;
			avocado::reversal(i, j, pi);
			sequence.emplace_back(i, j);
			breakpoints.clear();
		}
	}
	return sequence;
}
