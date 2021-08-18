#include "P035_CircularPrimes.h"
#include <iostream>
#include "libs/prime.h"
#include <string>

using namespace hackerrank_euler;

unsigned int P035_CircularPrimes::Solve(unsigned int n)
{
	uint32_t sum = 0;
	for (uint32_t ii = 1; ii < n; ++ii)
	{
		if (!IsPrime(ii))
			continue;
		std::string num_str = std::to_string(ii);
		bool prime = true;
		for (uint32_t jj = (uint32_t)num_str.length() - 1; jj >= 1; --jj)
		{
			std::rotate(num_str.begin(), num_str.begin() + 1, num_str.end());
			auto num = std::stoi(num_str);
			if (!IsPrime(num))
			{
				prime = false;
				break;
			}
		}
		if (prime)
			sum += ii;
	}
	return sum;
}

void P035_CircularPrimes::main()
{
	std::ios_base::sync_with_stdio(false);

	unsigned int n = 10;
	std::cin >> n;
	std::cout << Solve(n) << "\n";
}
