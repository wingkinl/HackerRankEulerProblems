#include "P025_NdigitFibonacciNumber.h"
#include <iostream>

// http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibFormula.html#section2
static inline long long fibWithNDigits(int n)
{
	return (long long)ceil(((n - 1) + log10(5) / 2)
		/ log10(1.6180339887498948));
}

long long P025_NdigitFibonacciNumber::Solve(int n)
{
	return fibWithNDigits(n);
}

void P025_NdigitFibonacciNumber::main()
{
	std::ios_base::sync_with_stdio(false);

	uint32_t T;
	std::cin >> T;
	for (uint32_t tt = 0; tt < T; ++tt)
	{
		int n;
		std::cin >> n;
		std::cout << Solve(n) << "\n";
	}
}
