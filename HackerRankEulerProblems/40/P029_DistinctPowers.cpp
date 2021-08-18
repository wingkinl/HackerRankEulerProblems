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

// The graphing idea was taken from here:
// https://stackoverflow.com/questions/2147692/project-euler-29?rq=1
//
// Use O to mark the first occurrences, X to mark the repeats
// Start by checking the base a=3, all the possible repeats would have to be
// other base m when they are e power to 3:
// e = 1  a = 3    OOOOOOOOO
// e = 2  a = 9      x x x x O O O O O
// e = 3  a = 27       x  x  x  O  x  O  O  O  O
// e = 4  a = 81         x   x   x   x   x   O   O   O   O
// 
// Because this is also the case for other base a = 2, 5, 6, 7, etc., 
// we can cache the repeat info and reuse it for all bases.
// 1) We can use an array of boolean flags to cache the repeat count
// 2) Use those flags to check the repeats and accumulate repeat count

int32_t P029_DistinctPowers::CalcRepeatPower(int32_t n)
{
	// We only need to check until the maximum base that can produce repeats
	// since 2 is the smallest number, need to find m in 2^m <= N for maximum base
	const int32_t kMaxBaseExp = IntLog<int32_t>(2, n);

	// Use unique_exp below as flags to mark the "unique" base a
	// "unique" only means a number is the first one that occurs
	std::vector<char> unique_exp(kMaxBaseExp * n + 1, 0);
	// The first group must be "unique"
	std::fill(unique_exp.begin() + 2, unique_exp.begin() + 2 + n - 1, true);
	// Use an array to count the repeats that accumulated up until exponent i
	std::vector<int32_t> repeats_at_exp = { 0,0 };
	repeats_at_exp.resize(kMaxBaseExp + 1);
	for (int32_t ii = 2; ii <= kMaxBaseExp; ++ii)
	{
		auto& repeat = repeats_at_exp[ii];
		int32_t exp = ii * 2;
		for (int32_t jj = 2; jj <= n; ++jj)
		{
			auto& marked = unique_exp[exp];
			if (marked)
				++repeat;
			else
				marked = true;
			exp += ii;
		}
		// Accumulate the repeats of previous exponents
		repeat += repeats_at_exp[ii - 1];
	}
	// There won't be repeats after square root of n
	const int32_t kMaxBase = FloorSqrt(n);
	// We need to skip computing bases that have already been checked
	// For example, for base a=2, 4, 8, 16, etc should be skipped
	// We can use yet another array of flags for this purpose.
	std::vector<char> base_marks(kMaxBase + 1);
	std::vector<int32_t> bases_to_be_checked;
	bases_to_be_checked.reserve(kMaxBase);
	for (int32_t ii = 2; ii <= kMaxBase; ++ii)
	{
		if (!base_marks[ii])
		{
			bases_to_be_checked.push_back(ii);
			int32_t base = ii;
			while (base <= kMaxBase)
			{
				base_marks[base] = true;
				base *= ii;
			}
		}
	}
	int32_t repeat = 0;
	for (auto base : bases_to_be_checked)
	{
		const int32_t kMaxExpForCurBase = IntLog<int32_t>(base, n);
		repeat += repeats_at_exp[kMaxExpForCurBase];
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
