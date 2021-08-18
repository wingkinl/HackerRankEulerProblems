#include "P040_ChampernowneConstant.h"
#include <iostream>
#include <algorithm>

P040_ChampernowneConstant::P040_ChampernowneConstant()
{
	const uint64_t kMax = 1000000000000000000;
	digit_bases.reserve(20);
	num_bases.reserve(20);
	for (uint64_t ii = 1, jj = 1, nn = 1; ; ++ii, jj *= 10)
	{
		num_bases.push_back(jj);
		digit_bases.push_back(nn);
		if (nn > kMax)
		{
			break;
		}
		nn += ii * jj * 9;
	}
}

uint32_t P040_ChampernowneConstant::Solve(const uint64_t (&digits)[7])
{
	uint32_t product = 1;
	bool has_zero = false;
	for (auto digit_idx : digits)
	{
		auto it = std::upper_bound(digit_bases.begin(), digit_bases.end(), digit_idx);
		--it;
		auto off = std::distance(digit_bases.begin(), it);
		const auto digit_len = off + 1;
		auto dv = lldiv(digit_idx - *it, digit_len);
		auto num = num_bases[off] + dv.quot;
		auto digit = (uint8_t)(num / num_bases[digit_len - dv.rem - 1] % 10);
		if (digit == 0)
			return 0U;
		product *= digit;
	}
	return product;
}

void P040_ChampernowneConstant::main()
{
	std::ios_base::sync_with_stdio(false);

	P040_ChampernowneConstant p;

	uint32_t T = 1;
	std::cin >> T;
	uint64_t digits[7] = {0};
	for (uint32_t ii = 0; ii < T; ++ii)
	{
		for (auto& digit_idx : digits)
			std::cin >> digit_idx;
		std::cout << p.Solve(digits) << "\n";
	}
}
