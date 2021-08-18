#include "P038_PandigitalMultiples.h"
#include <iostream>
#include <string>

static bool IsPandigital(uint32_t n, uint32_t K)
{
	bool used_digit[10] = { false };
	uint32_t digit_count = 0;
	for (uint32_t ii = 1; ; ++ii)
	{
		uint32_t v = n * ii;
		std::string str = std::to_string(v);
		if (digit_count + str.length() > K)
			return false;
		for (auto ch : str)
		{
			auto dd = (uint32_t)(ch - '0');
			if (dd == 0 || dd > K)
				return false;
			if (used_digit[dd])
				return false;
			used_digit[dd] = true;
		}
		digit_count += (uint32_t)str.length();
		if (digit_count == K)
			return true;
	}
	return false;
}

std::vector<unsigned int> P038_PandigitalMultiples::Solve(unsigned int n, unsigned int k)
{
	std::vector<unsigned int> result;
	result.reserve(n);
	n = std::min(n, 10000U);
	for (uint32_t ii = 2; ii < n; ++ii)
	{
		if (IsPandigital(ii, k))
			result.push_back(ii);
	}
	return result;
}

void P038_PandigitalMultiples::main()
{
	std::ios_base::sync_with_stdio(false);

	int n = 100, k = 8;
	std::cin >> n >> k;
	auto result = Solve(n, k);
	for (auto res : result)
		std::cout << res << "\n";
}
