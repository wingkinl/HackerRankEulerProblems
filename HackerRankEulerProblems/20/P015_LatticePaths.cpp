#include "P015_LatticePaths.h"
#include <iostream>
#include <vector>

unsigned int P015LatticePaths::Solve(int n, int m)
{
	std::vector<uint64_t> routes(n + 1, 1);
	for (int mm = m - 1; mm >= 0; --mm)
	{
		for (int nn = n - 1; nn >= 0; --nn)
		{
			routes[nn] = (routes[nn] + routes[nn + 1]) % 1000000007;
		}
	}
	return (unsigned int)(routes[0] % (1000000007));
}

void P015LatticePaths::main()
{
	std::ios_base::sync_with_stdio(false);
	int T;
	std::cin >> T;
	P015LatticePaths p;
	for (int t = 0; t < T; ++t)
	{
		int n, m;
		std::cin >> n >> m;
		std::cout << p.Solve(n, m) << "\n";
	}
}
