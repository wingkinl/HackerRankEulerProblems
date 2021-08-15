#include "P006_SumSquareDifference.h"
#include <iostream>

long P006SumSquareDifference::Solve(long n)
{
	long a = 0, b = 0;
	for (long ii = 1; ii <= n; ++ii)
	{
		a += ii;
		b += ii * ii;
	}
	return a * a - b;
}

void P006SumSquareDifference::main()
{
	int t;
	std::cin >> t;
	for (int ii = 0; ii < t; ii++)
	{
		long n;
		std::cin >> n;
		std::cout << Solve(n) << "\n";
	}
}