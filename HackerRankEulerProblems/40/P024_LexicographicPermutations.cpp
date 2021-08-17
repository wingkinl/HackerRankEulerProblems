#include "P024_LexicographicPermutations.h"
#include <iostream>

#ifndef _countof
	#define _countof(_Array) (sizeof(_Array) / sizeof(_Array[0]))
#endif // _countof

std::string P024_LexicographicPermutations::Solve(uint64_t n)
{
	std::string str = "abcdefghijklm";
	static const uint64_t kFactorials[] = {1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
	for (int f = _countof(kFactorials)-1; f >= 0; --f)
	{
		if (n > kFactorials[f])
		{
			auto dd = lldiv(n-1, kFactorials[f]);
			const size_t begin = str.length() - 1 - (f+1);
			const size_t pos = begin + (size_t)dd.quot;
			std::rotate(str.begin()+begin, str.begin()+pos, str.begin()+pos+1);
			if (dd.rem)
			{
				n = (uint64_t)dd.rem+1;
			}
			else
				break;
		}
	}
	return str;
}

void P024_LexicographicPermutations::main()
{
	std::ios_base::sync_with_stdio(false);

	uint32_t T;
	std::cin >> T;
	for (uint32_t ii = 0; ii < T; ++ii)
	{
		uint64_t n;
		std::cin >> n;
		std::cout << Solve(n) << std::endl;
	}
}
