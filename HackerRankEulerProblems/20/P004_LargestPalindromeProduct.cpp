#include "P004_LargestPalindromeProduct.h"
#include <iostream>
#include <algorithm>

void P004_LargestPalindromeProduct::InitPalindrome()
{
	all_palindromes.reserve(1000);
	char buffer[7] = { 0 };
	for (int n1 = 100; n1 < 1000; ++n1)
	{
		for (int n2 = 100; n2 < 1000; ++n2)
		{
			int nn = n1 * n2;
			if (nn > 100000 && nn % 11 == 0)
			{
				sprintf(buffer, "%d", nn);
				if (buffer[0] == buffer[5]
					&& buffer[1] == buffer[4]
					&& buffer[2] == buffer[3])
				{
					all_palindromes.push_back(nn);
				}
			}
		}
	}
	std::sort(all_palindromes.begin(), all_palindromes.end());
}

int P004_LargestPalindromeProduct::Solve(int n)
{
	if (all_palindromes.empty())
	{
		InitPalindrome();
	}
	for (int ii = (int)all_palindromes.size() - 1; ii >= 0; --ii)
	{
		if (all_palindromes[ii] < n)
			return all_palindromes[ii];
	}
	return 0;
}

void P004_LargestPalindromeProduct::main()
{
	std::ios_base::sync_with_stdio(false);
	int t;
	std::cin >> t;
	P004_LargestPalindromeProduct p;
	for (int ii = 0; ii < t; ii++)
	{
		long n;
		std::cin >> n;
		std::cout << p.Solve(n) << "\n";
	}
}
