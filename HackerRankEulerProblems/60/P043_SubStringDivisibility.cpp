#include "P043_SubStringDivisibility.h"
#include <iostream>
#include <algorithm>
#include <string>

uint64_t P043_SubStringDivisibility::Solve(uint32_t n)
{
	const int32_t aDivisors[] = {2,3,5,7,11,13,17};
	std::string strAll = "0123456789";

	uint64_t sum = 0;
	const auto kDigitLen = n + 1;
	std::string num_str = strAll.substr(0, kDigitLen);
	while (true)
	{
		bool match = true;
		for (uint32_t ii = 1; ii < kDigitLen-2; ++ii)
		{
			std::string cur_num_str = num_str.substr(ii, 3);
			auto num = std::stoi(cur_num_str);
			if (num % aDivisors[ii - 1] != 0)
			{
				match = false;
				break;
			}
		}
		if (match)
			sum += std::stoll(num_str);
		if (!std::next_permutation(num_str.begin(), num_str.begin()+kDigitLen))
			break;
	}
	return sum;
}

void P043_SubStringDivisibility::main()
{
	std::ios_base::sync_with_stdio(false);

	uint32_t n = 1;
	std::cin >> n;
	std::cout << Solve(n) << "\n";
}
