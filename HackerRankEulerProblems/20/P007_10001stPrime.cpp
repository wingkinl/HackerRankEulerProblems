#include "P007_10001stPrime.h"
#include <iostream>
#include "libs/prime.h"

using namespace hackerrank_euler;

int P00710001stPrime::Solve(int n)
{
	PrimeNumbers<int> primes;
	primes.InitPrimes(10000);
	return primes.nums[n-1];
}

void P00710001stPrime::main()
{
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
