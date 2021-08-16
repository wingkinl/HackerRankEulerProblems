#include "P003_LargestPrimeFactor.h"
#include <iostream>

uint64_t P003_LargestPrimeFactor::Solve(uint64_t n)
{
	uint64_t max = 2;
	while (n % 2 == 0)
	{
		n = n / 2;
	}
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n % i == 0)
		{
			n = n / i;
			if (i > max)
			{
				max = i;
			}
		}
	}
	if (n > 2 && n > max)
	{
		max = n;
	}
	return max;
}

void P003_LargestPrimeFactor::main()
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
