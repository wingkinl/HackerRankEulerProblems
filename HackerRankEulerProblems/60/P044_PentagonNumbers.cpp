#include "P044_PentagonNumbers.h"
#include <iostream>
#include "libs/numeric.h"

using namespace hackerrank_euler;

auto P044_PentagonNumbers::Solve(uint32_t max, uint32_t offset) -> Results
{
	Results res;
	for (auto n = (uint64_t)offset+1; n <= max; ++n)
	{
		auto pn = n * (3 * n - 1) / 2;
		auto n2 = n - offset;
		auto pk = n2 * (3 * n2 - 1) / 2;
		if (IsPentagonal(pn - pk) || IsPentagonal(pn + pk))
			res.push_back(pn);
	}
	return res;
}

void P044_PentagonNumbers::main()
{
	std::ios_base::sync_with_stdio(false);

	uint32_t n = 2, k = 1;
	std::cin >> n >> k;
	auto res = Solve(n, k);
	for (auto v : res)
	{
		std::cout << v << "\n";
	}
}
