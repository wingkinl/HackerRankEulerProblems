#include "P078_CoinPartitions.h"
#include <algorithm>
#include <iostream>
#include <vector>

enum {
	kMaxNum		= 1000,
	kResultMod	= 1000000007,
};

unsigned int P078_CoinPartitions::Solve(unsigned int n)
{
	std::vector<unsigned int> ways(n+1);
	ways[0] = 1;
	for (unsigned int ii = 1; ii < n; ++ii)
	{
		for (unsigned int jj = ii; jj <= n; ++jj)
		{
			ways[jj] = (ways[jj] + ways[jj - ii]) % kResultMod;
		}
	}
	return (ways[n] + 1) % kResultMod;
}

void P078_CoinPartitions::main()
{
	std::ios_base::sync_with_stdio(false);

	int T = 1;
	std::cin >> T;
	for (int ii = 0; ii < T; ++ii)
	{
		unsigned int n = 2;
		std::cin >> n;
		std::cout << Solve(n) << "\n";
	}
}
