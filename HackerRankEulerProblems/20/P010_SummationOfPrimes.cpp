#include "P010_SummationOfPrimes.h"
#include <iostream>
#include "libs/prime.h"

using namespace hackerrank_euler;

struct PrimeNumbersSum
{
	void InitPrimeSums(long n)
	{
		std::vector<long>		nums;
		std::vector<uint8_t>	prime_flags;
		prime_flags.resize(n + 1, true);

		prime_flags[0] = prime_flags[1] = false;
		const long kMaxNumToCheck = FloorSqrt(n);
		for (long ii = 2; ii <= kMaxNumToCheck; ++ii)
		{
			if (prime_flags[ii])
			{
				for (long jj = ii + ii; jj <= n; jj += ii)
					prime_flags[jj] = false;
			}
		}
		nums.resize(n);
		long sum = 0;
		sums.resize(n+1);
		size_t count = 0;
		for (long ii = 2; ii <= n; ++ii)
		{
			if (prime_flags[ii])
			{
				nums[count++] = ii;
				sum += ii;
			}
			sums[ii] = sum;
		}
	}
	std::vector<long>		sums;
};

long P010_SummationOfPrimes::Solve(long n)
{
	PrimeNumbersSum primes;
	primes.InitPrimeSums(n);
	return primes.sums[n];
}

void P010_SummationOfPrimes::main()
{
	std::ios_base::sync_with_stdio(false);
	int t;
	std::cin >> t;
	PrimeNumbersSum primes;
	primes.InitPrimeSums(1000000L);
	for (int ii = 0; ii < t; ii++)
	{
		int n;
		std::cin >> n;
		std::cout << primes.sums[n] << "\n";
	}
}
