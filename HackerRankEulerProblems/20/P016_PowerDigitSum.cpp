#include "P016_PowerDigitSum.h"
#include <iostream>
#include "libs/bigint.h"

using namespace hackerrank_euler;

uint64_t P016_PowerDigitSum::Solve(int n)
{
	BigInt numP2(2, n);
	uint64_t sum = 0;
	size_t nDigits = numP2.GetDigits();
	for (size_t ii = 0; ii < nDigits; ++ii)
		sum += numP2[ii];
	return sum;
}

void P016_PowerDigitSum::main()
{
	std::ios_base::sync_with_stdio(false);
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t)
	{
		int n;
		std::cin >> n;
		std::cout << P016_PowerDigitSum::Solve(n) << "\n";
	}
}
