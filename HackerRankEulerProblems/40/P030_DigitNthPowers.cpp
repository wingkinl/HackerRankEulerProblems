#include "P030_DigitNthPowers.h"
#include <iostream>
#include <string>

int P030_DigitNthPowers::Solve(int n)
{
	// Since n is in range [3,6], the maximum of 8 digits number
	// would be when 9^6 * 8 = 4251528, and it's only 7 digits.
	// Apparently it's not possible to have 8 digits number to 
	// get the sum that equals the powers.
	const int kMax = 8 * 9 * 9 * 9 * 9 * 9 * 9;
	int total = 0;
	for (int ii = 2; ii < kMax; ++ii)
	{
		std::string str = std::to_string(ii);
		int sum = 0;
		for (auto ch : str)
		{
			int dd = (int)(ch - '0');
			for (int jj = 1; jj < n; ++jj)
				dd *= (int)(ch - '0');
			sum += dd;
		}
		if (sum == ii)
		{
			total += sum;
		}
	}
	return total;
}

void P030_DigitNthPowers::main()
{
	std::ios_base::sync_with_stdio(false);

	int n = 3;
	std::cin >> n;
	std::cout << Solve(n) << "\n";
}
