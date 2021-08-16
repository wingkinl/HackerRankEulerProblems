#include "P013_LargeSum.h"
#include <iostream>

std::string P013_LargeSum::Solve(const std::vector<std::string>& vs)
{
	std::string result(50, '0');
	size_t carry = 0;
	for (int ii = 49; ii >= 0; --ii)
	{
		size_t sum = 0;
		for (auto& str : vs)
		{
			sum += str[ii] - '0';
		}
		sum += carry;
		carry = sum / 10;
		sum = sum % 10;
		result[ii] = (char)('0' + sum);
	}
	while (carry)
	{
		size_t m = carry % 10;
		result.insert(0, 1, (char)('0' + m));
		carry /= 10;
	}
	result.resize(10);
	return result;
}

void P013_LargeSum::main()
{
	std::ios_base::sync_with_stdio(false);
	int N;
	std::cin >> N;
	std::vector<std::string> vs(N);
	for (int ii = 0; ii < N; ++ii)
	{
		std::cin >> vs[ii];
	}
	P013_LargeSum p;
	std::cout << p.Solve(vs) << "\n";
}
