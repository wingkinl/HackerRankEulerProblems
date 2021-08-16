#include "P015_LatticePaths.h"
#include <iostream>
#include <vector>

// For a given grid, we can start from the bottom right corner
// and try to find routes back to every other point, and remember
// the number of routes at each point.
// There is exactly only 1 route to reach every point that locates
// on the right and bottom "edge", due to the fact that we can only
// move left and up (the opposite direction when start from top left).
//
// Here's the routes for a 2x2 grid:
//   0 0 1
//   0 0 1
//   1 1 X
// 
// From the bottom up, the number of routes equals to the number of 
// routes of its right and down point. Eventually we can get the result.
// 
//   6 3 1
//   3 2 1
//   1 1 X
//
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
