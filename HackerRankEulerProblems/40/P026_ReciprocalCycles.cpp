#include "P026_ReciprocalCycles.h"
#include <iostream>
#include <map>
#include <vector>

// this is just an implementation of the pen and paper computation process
static int GetRepeatingDecimal(int n)
{
	std::map<int, int> remainders;
	int numerator = 1;
	while (true)
	{
		auto dd = div(numerator, n);
		if (dd.rem == 0)
			break;
		auto it = remainders.find(dd.rem);
		if (it != remainders.end())
			return (int)remainders.size() - it->second;
		remainders.emplace(dd.rem, (int)remainders.size());
		numerator = dd.rem * 10;
	}
	return 0;
}

int P026_ReciprocalCycles::Solve(int n)
{
	int max_repeat = 0, num_with_max_repeat = 3;
	for (int ii = 3; ii < n; ++ii)
	{
		auto repeat = GetRepeatingDecimal(ii);
		if (repeat > max_repeat)
		{
			max_repeat = repeat;
			num_with_max_repeat = ii;
		}
	}
	return num_with_max_repeat;
}

void P026_ReciprocalCycles::main()
{
	std::ios_base::sync_with_stdio(false);

	int T;
	std::cin >> T;
	std::vector<int> vn(T);
	int max = 0;
	for (int tt = 0; tt < T; ++tt)
	{
		std::cin >> vn[tt];
		if (vn[tt] > max)
			max = vn[tt];
	}
	std::vector<int> nums_with_max_repeat(max + 1);
	int max_repeat = 0;
	int cur_num_with_max_repeat = 3;
	for (int ii = 3; ii < max; ++ii)
	{
		auto repeat = GetRepeatingDecimal(ii);
		if (repeat > max_repeat)
		{
			max_repeat = repeat;
			cur_num_with_max_repeat = ii;
		}
		nums_with_max_repeat[ii] = cur_num_with_max_repeat;
	}
	for (size_t jj = 0; jj < vn.size(); ++jj)
	{
		std::cout << nums_with_max_repeat[vn[jj]-1] << "\n";
	}
}
