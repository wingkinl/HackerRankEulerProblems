#include "P032_PandigitalProducts.h"
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

unsigned int P032_PandigitalProducts::Solve(unsigned int n)
{
	uint32_t sum = 0;

	std::set<uint32_t> products;

	std::vector<uint8_t> digits = { 1,2,3,4,5,6,7,8,9 };
	digits.resize((size_t)n);
	do
	{
		for (uint32_t num_a_len = 1; num_a_len < n; ++num_a_len)
		{
			for (uint32_t num_b_len = 1; num_b_len < n - num_a_len; ++num_b_len)
			{
				// c = a * b
				uint32_t num_c_len = n - num_a_len - num_b_len;
				if (num_c_len < num_a_len || num_c_len < num_b_len)
					break;
				size_t pos = 0;
				uint32_t aa = digits[pos];
				for (uint32_t ii = 2; ii <= num_a_len; ++ii)
				{
					aa *= 10;
					++pos;
					aa += digits[pos];
				}
				++pos;
				uint32_t bb = digits[pos];
				for (uint32_t ii = 2; ii <= num_b_len; ++ii)
				{
					bb *= 10;
					++pos;
					bb += digits[pos];
				}
				++pos;
				uint32_t cc = digits[pos];
				for (uint32_t ii = 2; ii <= num_c_len; ++ii)
				{
					cc *= 10;
					++pos;
					cc += digits[pos];
				}
				if (cc == aa * bb)
				{
					auto res = products.insert(cc);
					if (res.second)
					{
						sum += cc;
					}
				}
			}
		}
	} while (std::next_permutation(digits.begin(), digits.end()));

	return sum;
}

void P032_PandigitalProducts::main()
{
	std::ios_base::sync_with_stdio(false);

	uint32_t n = 4;
	std::cin >> n;
	std::cout << Solve(n) << "\n";
}
