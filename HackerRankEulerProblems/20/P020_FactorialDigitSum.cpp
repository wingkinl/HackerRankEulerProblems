#include "P020_FactorialDigitSum.h"
#include <iostream>
#include "libs/bigint.h"

using namespace hackerrank_euler;

uint64_t P020_FactorialDigitSum::Solve(int n)
{
	uint64_t sum = 0;
	BigInt num(1);
	for (int ii = 2; ii <= n; ++ii)
		num *= ii;
	for (int64_t jj = (int64_t)num.GetDigits()-1; jj >= 0; --jj)
		sum += num[jj];
	return sum;
}

void P020_FactorialDigitSum::main()
{
	std::ios_base::sync_with_stdio(false);
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t)
	{
		int n;
		std::cin >> n;
		std::cout << Solve(n) << std::endl;
	}
}
