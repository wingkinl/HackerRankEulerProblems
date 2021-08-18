#include "P027_QuadraticPrimes.h"
#include "libs/prime.h"
#include <iostream>
#include <algorithm>

using namespace hackerrank_euler;

std::pair<int,int> P027_QuadraticPrimes::Solve(int n)
{
	PrimeNumbers<int> primes;
	primes.InitPrimes(n*100);
	int32_t result_a = 0, result_b = 0, max_count = 0;
	for (int32_t a = -n; a <= n; ++a)
	{
		for (int32_t b = -n; b <= n; ++b)
		{
			int32_t nn = 0;
			for (;;)
			{
				int32_t val = nn * nn + a * nn + b;
				if (std::binary_search(primes.nums.begin(), primes.nums.end(), val))
					++nn;
				else
					break;
			}
			if (nn > max_count)
			{
				result_a = a;
				result_b = b;
				max_count = nn;
			}
		}
	}
	return std::make_pair(result_a, result_b);
}

void P027_QuadraticPrimes::main()
{
	std::ios_base::sync_with_stdio(false);

	int n = 0;
	std::cin >> n;
	auto result = Solve(n);
	std::cout << result.first << ' ' << result.second << "\n";
}
