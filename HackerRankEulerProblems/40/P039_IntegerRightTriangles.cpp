#include "P039_IntegerRightTriangles.h"
#include <iostream>
#include <vector>
#include <libs/numeric.h>

P039_IntegerRightTriangles::P039_IntegerRightTriangles(unsigned int max_perimeter)
{
	std::vector<uint32_t> perimeter_count(max_perimeter + 1);

	// https://en.wikipedia.org/wiki/Pythagorean_triple#Generating_a_triple
	// a = m^2 - n^2, b = 2mn, c = m^2 + n^2
	// p = a + b + c = 2m^2 + 2mn = 2m(m+n)
	for (uint64_t m = 2; 2 * m * (m + 1) <= max_perimeter; ++m)
	{
		for (uint64_t n = 1; n < m; ++n)
		{
			if (m & 1 && n & 1)
				continue;
			if (hackerrank_euler::gcd(m, n) > 1)
				continue;
			auto a = m * m - n * n;
			auto b = 2 * m * n;
			auto c = m * m + n * n;
			auto p = a + b + c;
			for (int32_t k = 1; k <= max_perimeter / p; ++k)
			{
				auto pp = p * k;
				if (pp > max_perimeter)
					break;
				auto& count = perimeter_count[(uint32_t)pp];
				++count;
			}
		}
	}

	uint32_t max_count = 0;
	for (size_t pp = 0; pp < perimeter_count.size(); ++pp)
	{
		if (perimeter_count[pp] > max_count)
		{
			max_count = perimeter_count[pp];
			max_perimeters.insert((uint32_t)pp);
		}
	}
}

unsigned int P039_IntegerRightTriangles::Solve(unsigned int n)
{
	auto it = max_perimeters.upper_bound(n);
	--it;
	return *it;
}

void P039_IntegerRightTriangles::main()
{
	std::ios_base::sync_with_stdio(false);

	uint32_t T = 1;
	std::cin >> T;
	std::vector<uint32_t> vn(T);
	uint32_t max_n = 0;
	for (uint32_t ii = 0; ii < T; ++ii)
	{
		auto& n = vn[ii];
		std::cin >> n;
		if (n > max_n)
			max_n = n;
	}

	P039_IntegerRightTriangles p(max_n);
	for (auto n : vn)
		std::cout << p.Solve(n) << "\n";
}
