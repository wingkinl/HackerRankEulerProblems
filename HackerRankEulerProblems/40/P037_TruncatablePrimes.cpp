#include "P037_TruncatablePrimes.h"
#include <iostream>
#include <string>
#include "libs/prime.h"

unsigned int P037_TruncatablePrimes::Solve(int N)
{
	hackerrank_euler::PrimeNumbers<uint32_t> prime;
	prime.InitPrimes(N);
	uint32_t total = 0;
	// skip 2,3,5,7
	for (auto it = prime.nums.begin() + 4; it != prime.nums.end(); ++it)
	{
		std::string str = std::to_string(*it);
		size_t len = str.length();
		bool truncatable = true;
		for (size_t ii = 1; ii <= len - 1; ++ii)
		{
			std::string temp_str = str.substr(0, ii);
			auto num = std::stoi(temp_str);
			if (!prime.prime_flags[num])
			{
				truncatable = false;
				break;
			}
		}
		if (!truncatable)
			continue;
		for (size_t ii = 1; ii <= len - 1; ++ii)
		{
			std::string temp_str = str.substr(len - ii, ii);
			auto num = std::stoi(temp_str);
			if (!prime.prime_flags[num])
			{
				truncatable = false;
				break;
			}
		}
		if (truncatable)
			total += *it;
	}
	return total;
}

void P037_TruncatablePrimes::main()
{
	std::ios_base::sync_with_stdio(false);

	int n = 10;
	std::cin >> n;
	std::cout << Solve(n) << "\n";
}
