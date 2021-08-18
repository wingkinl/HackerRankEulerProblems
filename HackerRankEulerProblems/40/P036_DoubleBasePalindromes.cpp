#include "P036_DoubleBasePalindromes.h"
#include <iostream>
#include <string>

static std::string itoaReversed(int N, int K)
{
	std::string str;
	str.reserve(15);
	while (true)
	{
		auto dd = div(N, K);
		str.push_back(dd.rem + '0');
		if (dd.quot == 0)
			break;
		N = dd.quot;
	}
	return str;
}

static bool IsPalindromic(const std::string& str)
{
	auto len = str.length();
	size_t half = len / 2;
	for (size_t ii = 0; ii < half; ++ii)
	{
		if (str[ii] != str[len - ii - 1])
			return false;
	}
	return true;
}

unsigned int P036_DoubleBasePalindromes::Solve(int n, int k)
{
	uint32_t sum = 0;
	for (int ii = 1; ii < n; ++ii)
	{
		std::string str_10 = std::to_string(ii);
		if (!IsPalindromic(str_10))
			continue;
		std::string str_base = itoaReversed(ii, k);
		if (IsPalindromic(str_base))
			sum += ii;
	}
	return sum;
}

void P036_DoubleBasePalindromes::main()
{
	std::ios_base::sync_with_stdio(false);

	int n = 10, k = 2;
	std::cin >> n >> k;
	std::cout << Solve(n, k) << "\n";
}
