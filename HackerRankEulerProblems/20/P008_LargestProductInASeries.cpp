#include "P008_LargestProductInASeries.h"
#include <iostream>

int P008LargestProductInASeries::Solve(const std::string& str, int consecutive)
{
	const auto kLen = (int)str.length();
	int max_product = 0;
	for (int digit = 0; digit < kLen - consecutive + 1; ++digit)
	{
		int product = 1;
		for (int ii = 0; ii < consecutive; ++ii)
		{
			product *= str[digit + ii] - '0';
		}
		if (product > max_product)
		{
			max_product = product;
		}
	}
	return max_product;
}

void P008LargestProductInASeries::main()
{
	int tt;
	std::cin >> tt;

	for (int t = 0; t < tt; ++t)
	{
		int nn, kk;
		std::cin >> nn >> kk;
		std::string str;
		std::cin >> str;
		int nMax = Solve(str, kk);
		std::cout << nMax << "\n";
	}
}
