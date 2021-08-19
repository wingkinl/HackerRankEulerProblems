#include "P046_GoldbachOtherConjecture.h"
#include <iostream>
#include "libs/prime.h"

unsigned int P046_GoldbachOtherConjecture::Solve(unsigned int n)
{
	unsigned int sum = 0;
	for (unsigned int jj = 1; ; ++jj)
	{
		unsigned int v = jj * jj * 2;
		if (v >= n)
			break;
		if (hackerrank_euler::IsPrime(n - v))
			++sum;
	}
	return sum;
}

void P046_GoldbachOtherConjecture::main()
{
	std::ios_base::sync_with_stdio(false);

	unsigned int T = 1;
	std::cin >> T;
	for (unsigned int ii = 0; ii < T; ++ii)
	{
		unsigned int n = 9;
		std::cin >> n;
		std::cout << Solve(n) << "\n";
	}
}
