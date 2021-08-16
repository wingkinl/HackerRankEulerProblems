#include "P001_MultiplesOf3And5.h"
#include <iostream>

static inline uint64_t GetSum(uint64_t n, uint64_t count)
{
	uint64_t sum = 0;
	if (count)
		sum = count * (count + 1) / 2 * n;
	return sum;
}

uint64_t P001MultiplesOf3And5::Solve(uint32_t n)
{
	--n;
	size_t sum = GetSum(3, n / 3) + GetSum(5, n / 5) - GetSum(15, n / 15);
	return sum;
}

void P001MultiplesOf3And5::main()
{
	std::ios_base::sync_with_stdio(false);
	int t;
	std::cin >> t;
	for (int ii = 0; ii < t; ii++)
	{
		int n;
		std::cin >> n;
		auto sum = Solve(n);
		std::cout << sum << "\n";
	}
}
