#include "P018_MaximumPathSumI.h"
#include <iostream>
#include "libs/numeric.h"
using namespace hackerrank_euler;

// Starting from the second to the last row, we compute the maximum total
// for each point, until we reach the root.
int P018_MaximumPathSumI::Solve(std::vector<int> tri)
{
	const int n = (int)(FloorSqrt(tri.size() * 8 + 1) - 1) / 2;
	for (int ii = n-2; ii >= 0; --ii)
	{
		for (int jj = 0; jj <= ii; ++jj)
		{
			auto offset = ii * (ii + 1) / 2;
			tri[offset + jj] += std::max(tri[offset+ii+jj+1], tri[offset+ii+jj+2]);
		}
	}
	return tri[0];
}

void P018_MaximumPathSumI::main()
{
	std::ios_base::sync_with_stdio(false);
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t)
	{
		int n;
		std::cin >> n;
		std::vector<int> tri(n*(n+1)/2);
		for (auto& v : tri)
			std::cin >> v;
		std::cout << Solve(tri) << "\n";
	}
}
