#include "P007_10001stPrime.h"
#include <iostream>
#include "libs/prime.h"

using namespace hackerrank_euler;

int P007_10001stPrime::Solve(int n)
{
	PrimeNumbers<int> primes;
	primes.InitPrimes(10000);
	return primes.nums[n-1];
}

void P007_10001stPrime::main()
{
	std::ios_base::sync_with_stdio(false);
	int t;
	std::cin >> t;
	PrimeNumbers<int> primes;
	primes.InitPrimes(10000);
	for (int ii = 0; ii < t; ii++)
	{
		int n = 0;
		std::cin >> n;
		std::cout << primes.nums[n-1] << "\n";
	}
}
