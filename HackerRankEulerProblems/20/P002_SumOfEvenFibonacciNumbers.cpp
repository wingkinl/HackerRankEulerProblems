#include "P002_SumOfEvenFibonacciNumbers.h"
#include <iostream>

uint64_t P002_SumOfEvenFibonacciNumbers::Solve(uint32_t n)
{
	uint64_t n1 = 0, n2 = 1;
	uint64_t sum = 0;
	uint64_t fib = n1 + n2;
	while (fib < n)
	{
		if (!(fib & 1))
			sum += fib;
		n1 = n2;
		n2 = fib;
		fib = n1 + n2;
	}
	return sum;
}

void P002_SumOfEvenFibonacciNumbers::main()
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
