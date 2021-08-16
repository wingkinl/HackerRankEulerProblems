#include "P021_AmicableNumbers.h"
#include <iostream>
#include "libs/numeric.h"

uint64_t P021_AmicableNumbers::Solve(uint32_t n)
{
	Init(n);
	int64_t sum = 0;
	for (uint32_t ii = 0; ii < n; ++ii)
	{
		auto& info = amicable_num_info[ii];
		if (info.has_amicable)
			sum += ii;
	}
	return sum;
}

void P021_AmicableNumbers::Init(uint32_t n)
{
	if ((size_t)n <= amicable_num_info.size())
		return;
	const auto start = std::max(2U, (uint32_t)amicable_num_info.size());
	amicable_num_info.resize((size_t)n);
	for (uint32_t ii = start; ii < n; ++ii)
	{
		uint32_t sum = hackerrank_euler::get_sum_of_divisors(ii);
		if (sum < n)
		{
			if (amicable_num_info[ii].pairs.count(sum))
			{
				amicable_num_info[ii].has_amicable = true;
				amicable_num_info[sum].has_amicable = true;
			}
			amicable_num_info[sum].pairs.insert(ii);
		}
	}
}

void P021_AmicableNumbers::main()
{
	std::ios_base::sync_with_stdio(false);
	uint32_t T;
	std::cin >> T;
	std::vector<uint32_t> vn(T);
	uint32_t max = 0;
	for (uint32_t ii = 0; ii < T; ++ii)
	{
		std::cin >> vn[ii];
		if (vn[ii] > max)
			max = vn[ii];
	}

	P021_AmicableNumbers p;

	p.Init(max);
	for (uint32_t n : vn)
		std::cout << p.Solve(n) << "\n";
}
