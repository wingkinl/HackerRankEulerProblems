#include "P078_CoinPartitions.h"
#include <algorithm>
#include <iostream>
#include <vector>

enum {
	kResultMod	= 1000000007,
};

P078_CoinPartitions::P078_CoinPartitions(int max)
{
	partitions_.reserve((size_t)max + 1);
	partitions_.push_back(1);
}

// The solution is a minor modified version of problem 076
int P078_CoinPartitions::SolveSlow(int n)
{
	std::vector<int> ways(n + 1);
	ways[0] = 1;
	for (int ii = 1; ii < n; ++ii)
	{
		for (int jj = ii; jj <= n; ++jj)
		{
			ways[jj] = (ways[jj] + ways[jj - ii]) % kResultMod;
		}
	}
	return (ways[n] + 1) % kResultMod;
}

// https://en.wikipedia.org/wiki/Partition_%28number_theory%29#Recurrence_formula
int P078_CoinPartitions::Solve(int n)
{
	if (n < partitions_.size())
		return partitions_[n];
	for (int pn = (int)partitions_.size(); pn <= n; ++pn)
	{
		int64_t val = 0;
		int plus = 1;
		int previous_pn_offset = 1;
		int offset[2] = { 1, 3 };
		for (uint32_t ii = 0; previous_pn_offset <= pn; ++ii)
		{
			val += plus * (int64_t)partitions_[pn - previous_pn_offset];
			val %= kResultMod;
			auto odd = ii & 1;
			previous_pn_offset += offset[odd];
			offset[odd] += 1 + odd;
			if (odd)
				plus = -plus;
		}
		if (val < 0)
			val += kResultMod;
		partitions_.push_back((int)val);
	}
	return partitions_[n];
}

void P078_CoinPartitions::main()
{
	std::ios_base::sync_with_stdio(false);

	int T = 1;
	std::cin >> T;
	std::vector<int> vn(T);
	int max = 0;
	for (int ii = 0; ii < T; ++ii)
	{
		auto& n = vn[ii];
		std::cin >> n;
		if (n > max)
			max = n;
	}
	P078_CoinPartitions p(max);
	for (auto n : vn)
	{
		std::cout << p.Solve(n) << "\n";
	}
}
