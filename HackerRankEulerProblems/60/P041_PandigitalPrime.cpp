#include "P041_PandigitalPrime.h"
#include <iostream>
#include <algorithm>
#include "libs/prime.h"
#include <string>

P041_PandigitalPrime::P041_PandigitalPrime(int max)
{
	const auto kMaxDigitLen = std::to_string(max).length();
	std::string digits_str = "123456789";
	pandigital_primes.reserve(600);
	for (auto digit_len = 2; digit_len <= kMaxDigitLen; ++digit_len)
	{
		std::string cur_num_str = digits_str.substr(0, digit_len);
		while (true)
		{
			auto num = std::stoi(cur_num_str);
			if (hackerrank_euler::IsPrime(num))
				pandigital_primes.push_back(num);
			if (!std::next_permutation(cur_num_str.begin(), cur_num_str.begin() + digit_len))
				break;
		}
	}
	std::sort(pandigital_primes.begin(), pandigital_primes.end());
}

int P041_PandigitalPrime::Solve(int n)
{
	auto it = std::upper_bound(pandigital_primes.begin(), pandigital_primes.end(), n);
	if (it == pandigital_primes.begin())
		return -1;
	return *(it - 1);
}

void P041_PandigitalPrime::main()
{
	std::ios_base::sync_with_stdio(false);

	uint32_t T = 1;
	std::cin >> T;
	std::vector<uint32_t> vn(T);
	uint32_t max = 0;
	for (uint32_t ii = 0; ii < T; ++ii)
	{
		auto& n = vn[ii];
		std::cin >> n;
		if (n > max)
			max = n;
	}
	P041_PandigitalPrime p(max);
	for (auto n : vn)
		std::cout << p.Solve(n) << "\n";
}
