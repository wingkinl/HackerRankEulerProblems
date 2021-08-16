#include "P012_HighlyDivisibleTriangularNumber.h"
#include <iostream>


int P012HighlyDivisibleTriangularNumber::Solve(int n)
{
	int tri = 0;
	if (!tri_divisors.empty() && known_max_divisor > n)
	{
		for (auto& v : tri_divisors)
		{
			if (v.second > n)
			{
				tri = v.first;
				break;
			}
		}
	}
	else
	{
		int sum = 0;
		if (!tri_divisors.empty())
			sum = tri_divisors.back().first;
		const int kStart = (int)tri_divisors.size() + 1;
		for (int ii = kStart; ; ++ii)
		{
			sum += ii;
			int divisors = 0;
			for (int jj = 1; jj * jj <= sum; ++jj)
			{
				if (sum % jj == 0)
				{
					divisors += 1 + (sum / jj != jj);
				}
			}
			if (divisors > known_max_divisor)
				known_max_divisor = divisors;
			tri_divisors.push_back(std::make_pair(sum, divisors));
			if (divisors > n)
			{
				tri = sum;
				break;
			}
		}
	}
	return tri;
}

void P012HighlyDivisibleTriangularNumber::main()
{
	int T;
	std::cin >> T;
	P012HighlyDivisibleTriangularNumber p;
	for (int t = 0; t < T; ++t)
	{
		int n;
		std::cin >> n;
		std::cout << p.Solve(n) << "\n";
	}
}
