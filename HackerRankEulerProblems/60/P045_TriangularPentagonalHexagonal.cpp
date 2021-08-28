#include "P045_TriangularPentagonalHexagonal.h"
#include <iostream>
#include "libs/numeric.h"

using namespace hackerrank_euler;

auto P045_TriangularPentagonalHexagonal::Solve(uint64_t max, uint32_t a, uint32_t b) -> Results
{
	Results res;
	if (a == 3 && b == 5)
	{
		for (uint64_t n = 1; ; ++n)
		{
			auto pn = n * (3 * n - 1) / 2;
			if (pn >= max)
				break;
			if (IsTriangle(pn))
				res.push_back(pn);
		}
	}
	else
	{
		// a == 5, b == 6
		for (uint64_t n = 1; ; ++n)
		{
			auto hn = n * (2 * n - 1);
			if (hn >= max)
				break;
			if (IsPentagonal(hn))
				res.push_back(hn);
		}
	}
	return res;
}

void P045_TriangularPentagonalHexagonal::main()
{
	std::ios_base::sync_with_stdio(false);

	uint64_t n = 2;
	uint32_t a = 3, b = 5;
	std::cin >> n >> a >> b;
	auto res = Solve(n, a, b);
	for (auto v : res)
	{
		std::cout << v << "\n";
	}
}
