#include "P029_DistinctPowers.h"
#include <iostream>
#include "libs/prime.h"
#include <vector>

using namespace hackerrank_euler;

uint64_t P029_DistinctPowers::Solve(int32_t n)
{
	int32_t repeat = 0;
	if (n > 3)
		repeat = CalcRepeatPower(n);

	uint64_t total = (uint64_t)(n - 1) * (uint64_t)(n - 1);
	auto unique = total - repeat;
	return unique;
}

int32_t P029_DistinctPowers::CalcRepeatPower(int32_t n)
{
	// we only need to check until the maximum base that can produce repeats
	// since 2 is the smallest number, need to find m in 2^m <= N for maximum base
	const int32_t max_base_exp = IntLog<int32_t>(2, n);
	// for any given base a, the possible repeats happen for later base that equal to:
	// a^2, a^3, a^4,... a^m, so the exponents to the same base (a) are:
	// 2*b, 3*b, 4*b,... m^b
	// use unique_exp below to mark the "unique" base a
	// "unique" only means a number is the first occurs in a series
	std::vector<char> unique_exp(max_base_exp * n + 1, 0);
	// the first group must be "unique"
	std::fill(unique_exp.begin() + 2, unique_exp.begin() + 2 + n - 1, true);
	// use an array to count the repeats since exp=2*b
	std::vector<int32_t> repeats = { 0,0 };
	repeats.resize(max_base_exp + 1);
	for (int32_t ii = 2; ii <= max_base_exp; ++ii)
	{
		auto& repeat = repeats[ii];
		int32_t exp_val = ii * 2;
		for (int32_t jj = 2; jj <= n; ++jj)
		{
			auto& exp = unique_exp[exp_val];
			if (exp)
				++repeat;
			else
				exp = true;
			exp_val += ii;
		}
		repeat += repeats[ii - 1];
	}

	int32_t max_base = FloorSqrt(n);
	std::vector<char> base_marks(max_base + 1);
	std::vector<int32_t> bases;
	bases.reserve(max_base);
	for (int32_t ii = 2; ii <= max_base; ++ii)
	{
		if (!base_marks[ii])
		{
			bases.push_back(ii);
			int32_t base = ii;
			while (base <= max_base)
			{
				base_marks[base] = true;
				base *= ii;
			}
		}
	}
	int32_t repeat = 0;
	for (auto base : bases)
	{
		int32_t max_exp = IntLog<int32_t>(base, n);
		repeat += repeats[max_exp];
	}
	return repeat;
}

void P029_DistinctPowers::main()
{
	std::ios_base::sync_with_stdio(false);

	int32_t n = 100000;
	std::cin >> n;
	std::cout << Solve(n) << "\n";
}
