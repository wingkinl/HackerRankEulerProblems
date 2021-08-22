#include "P076_CountingSummations.h"
#include <algorithm>
#include <iostream>
#include <vector>

enum {
	kMaxNum		= 1000,
	kMaxSub		= kMaxNum/2,
	kResultMod	= 1000000007,
};

unsigned int P076_CountingSummations::Solve(unsigned int n)
{
	unsigned int ways_dp[kMaxSub+1][kMaxSub+1] = { 0 };
	const auto kHalf = n / 2;
	unsigned int total = 0;
	for (unsigned int sub = 1; sub <= kHalf; ++sub)
	{
		for (unsigned int num = 1; num < n; ++num)
		{
		}
		total += 1 + ways_dp[n-1][sub];
	}
	return total % kResultMod;
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
