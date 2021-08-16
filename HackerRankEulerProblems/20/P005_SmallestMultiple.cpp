#include "P005_SmallestMultiple.h"
#include <iostream>
#include "libs/numeric.h"

int P005_SmallestMultiple::Solve(int n)
{
	int v = 1;
	for (int ii = 2; ii <= n; ++ii)
	{
		v = hackerrank_euler::lcm(v, ii);
	}
	return v;
}

void P005_SmallestMultiple::main()
{
	std::ios_base::sync_with_stdio(false);
	int t;
	std::cin >> t;
	for (int ii = 0; ii < t; ii++)
	{
		long n;
		std::cin >> n;
		std::cout << Solve(n) << "\n";
	}
}
