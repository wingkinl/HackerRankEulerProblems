#include "P047_DistinctPrimesFactors.h"
#include <iostream>
#include "libs/prime.h"

std::vector<unsigned int> P047_DistinctPrimesFactors::Solve(unsigned int n, unsigned int k)
{
	unsigned int max = n + k - 1;
	std::vector<unsigned int> primes(max + 1, 0);
	for (unsigned int ii = 2; ii <= max; ++ii)
	{
		if (primes[ii] == 0)
		{
			for (unsigned int jj = ii; jj <= max; jj += ii)
				++primes[jj];
		}
	}
	std::vector<unsigned int> results;
	for (unsigned int ii = 2, continuos_match = 0; ii <= max; ++ii)
	{
		if (primes[ii] == k)
		{
			++continuos_match;
			if (continuos_match >= k)
				results.push_back(ii - k + 1);
		}
		else
		{
			continuos_match = 0;
		}
	}
	return results;
}

void P047_DistinctPrimesFactors::main()
{
	std::ios_base::sync_with_stdio(false);

	unsigned int n = 20, k = 2;
	std::cin >> n >> k;

	for (auto res : Solve(n, k))
		std::cout << res << "\n";
}
