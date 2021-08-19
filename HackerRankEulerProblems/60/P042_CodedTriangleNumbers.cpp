#include "P042_CodedTriangleNumbers.h"
#include <iostream>

int64_t P042_CodedTriangleNumbers::Solve(int64_t n)
{
	for (int64_t ii = (int64_t)(sqrt(2*n)+0.5); ii >= 1; --ii)
	{
		auto v = ii * (ii + 1) / 2;
		if (v == n)
			return ii;
		else if (v < n)
			break;
	}
	return -1;
}

void P042_CodedTriangleNumbers::main()
{
	std::ios_base::sync_with_stdio(false);

	uint32_t T = 1;
	std::cin >> T;
	for (uint32_t ii = 0; ii < T; ++ii)
	{
		uint64_t n = 1;
		std::cin >> n;
		std::cout << Solve(n) << std::endl;
	}
}
