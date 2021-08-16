#include "P009_SpecialPythagoreanTriplet.h"
#include <iostream>

int P009SpecialPythagoreanTriplet::Solve(int n)
{
	int max = -1;
	for (int a = 1; a < n / 3; ++a)
	{
		int b = (n * n - 2 * n * a) / (n * 2 - a * 2);
		int c = n - a - b;
		if (c * c == (a * a + b * b))
		{
			int val = a * b * c;
			if (val > max)
				max = val;
		}
	}
	return max;
}

void P009SpecialPythagoreanTriplet::main()
{
	std::ios_base::sync_with_stdio(false);
	int t;
	std::cin >> t;
	for (int ii = 0; ii < t; ii++)
	{
		long n;
		std::cin >> n;
		std::cout << Solve(n) << "\n";
	}
}
