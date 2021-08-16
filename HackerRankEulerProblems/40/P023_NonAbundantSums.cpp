#include "P023_NonAbundantSums.h"
#include <iostream>
#include "libs/numeric.h"
#include <vector>

void P023_NonAbundantSums::Init(uint32_t n)
{
	if (n <= max_num)
		return;
	const auto start = max_num ? max_num : 2;
	for (uint32_t ii = start; ii < n; ++ii)
	{
		uint32_t sum = hackerrank_euler::get_sum_of_divisors(ii);
		if (sum > ii)
			abundant.insert(ii);
	}
	max_num = n;
}

bool P023_NonAbundantSums::Solve(uint32_t n)
{
	if (n > 28123)
		return true;
	Init(n);
	for (uint32_t ii = n >> 1; ii >= 1; --ii)
	{
		bool bb = abundant.count(ii)
			&& abundant.count(n - ii);
		if (bb)
			return true;
	}
	return false;
}

void P023_NonAbundantSums::main()
{
	std::ios_base::sync_with_stdio(false);
	uint32_t T;
	std::cin >> T;
	P023_NonAbundantSums p;
	for (uint32_t ii = 0; ii < T; ++ii)
	{
		uint32_t n = 0;
		std::cin >> n;
		std::cout << (p.Solve(n) ? "YES" : "NO") << "\n";
	}
}
