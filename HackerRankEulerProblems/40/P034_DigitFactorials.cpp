#include "P034_DigitFactorials.h"
#include <iostream>
#include "libs/numeric.h"
#include <string>

using namespace hackerrank_euler;

uint64_t P034_DigitFactorials::Solve(uint32_t n)
{
	static const uint32_t kFactorials[] = {
		Factorial(0),
		Factorial(1),
		Factorial(2),
		Factorial(3),
		Factorial(4),
		Factorial(5),
		Factorial(6),
		Factorial(7),
		Factorial(8),
		Factorial(9),
	};
	uint64_t total = 0;
	for (uint32_t ii = 10; ii < n; ++ii)
	{
		uint32_t digits[10] = { 0 };
		auto num_str = std::to_string(ii);
		for (auto ch : num_str)
			++digits[ch - '0'];
		uint64_t sum = 0;
		for (int jj = 0; jj < 10; ++jj)
		{
			sum += digits[jj] * kFactorials[jj];
		}
		if (sum % ii == 0)
			total += ii;
	}
	return total;
}

void P034_DigitFactorials::main()
{
	std::ios_base::sync_with_stdio(false);

	uint32_t n = 10;
	std::cin >> n;
	std::cout << Solve(n) << "\n";
}
