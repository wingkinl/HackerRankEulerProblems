#include "P014_LongestCollatzSequence.h"
#include <iostream>

uint64_t P014LongestCollatzSequence::GetTermStep(uint64_t term)
{
	if (term == 1)
		return 0;
	if (term_steps[term])
		return term_steps[term];
	uint64_t step = 0;
	uint64_t next_term = term;
	do
	{
		if (next_term & 1)
			next_term = next_term * 3 + 1;
		else
			next_term = next_term >> 1;
		++step;
	} while (next_term > kMaximum);
	return step + GetTermStep(next_term);
}

uint64_t P014LongestCollatzSequence::Solve(uint64_t n)
{
	if (max_step_nums.empty())
	{
		term_steps.resize(kMaximum + 1);
		term_steps[0] = 1;
		term_steps[1] = 1;
		uint64_t step = 0;
		// even term
		for (uint64_t ii = 2; ii <= kMaximum; ii <<= 1)
		{
			++step;
			term_steps[ii] = step;
		}
		for (uint64_t ii = 3; ii <= kMaximum; ++ii)
		{
			term_steps[ii] = GetTermStep(ii);
		}

		max_step_nums.resize(kMaximum + 1);
		max_step_nums[1] = 1;
		for (uint64_t ii = 2; ii <= kMaximum; ++ii)
		{
			auto prev_max_step_num = max_step_nums[ii - 1];
			if (term_steps[ii] >= term_steps[prev_max_step_num])
				max_step_nums[ii] = ii;
			else
				max_step_nums[ii] = prev_max_step_num;
		}
	}
	return max_step_nums[n];
}

void P014LongestCollatzSequence::main()
{
	std::ios_base::sync_with_stdio(false);
	int T;
	std::cin >> T;
	P014LongestCollatzSequence p;
	for (int t = 0; t < T; ++t)
	{
		uint64_t n;
		std::cin >> n;
		std::cout << p.Solve(n) << "\n";
	}
}
