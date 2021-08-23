#include "P076_CountingSummations.h"
#include <algorithm>
#include <iostream>

enum {
	kMaxNum		= 1000,
	kResultMod	= 1000000007,
};

unsigned int P076_CountingSummations::Solve(unsigned int n)
{
	unsigned int ways[kMaxNum+1] = {0};
	ways[0] = 1;
	for (unsigned int ii = 1; ii < n; ++ii)
	{
		for (unsigned int jj = ii; jj <= n; ++jj)
		{
			ways[jj] = (ways[jj] + ways[jj - ii]) % kResultMod;
		}
	}
	return ways[n] % kResultMod;
}

void P076_CountingSummations::main()
{
	std::ios_base::sync_with_stdio(false);

	unsigned int T = 1;
	std::cin >> T;
	for (unsigned int ii = 0; ii < T; ++ii)
	{
		unsigned int n = 2;
		std::cin >> n;
		std::cout << Solve(n) << "\n";
	}
}
