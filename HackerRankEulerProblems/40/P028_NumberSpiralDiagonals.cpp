#include "P028_NumberSpiralDiagonals.h"
#include <iostream>
#include "libs/numeric.h"

using namespace hackerrank_euler;

uint64_t P028_NumberSpiralDiagonals::Solve(uint64_t n)
{
	// x=0,1,2,...
	// for a given square at x
	// the upper right number is K=(2*x+1)^2 = 4*x^2+4*x+1
	// the other 3 numbers are:
	// K-2*x, K-4*x, K-6*x
	// the sum of all 4 numbers are:
	// sum(x) = 4*K-12*x = 16*x^2 + 4*x + 4
	// we need the sum of all squares
	// 1) for x^2, it's x*(x+1)*(2*x+1)/6
	// 2) for x, it's x*(x+1)/2
	// so the total sum is:
	// Sumtotal = 16*x*(x+1)*(2*x+1)/6 + 4*x*(x+1)/2 + 4*x
	// = 8*x*(x+1)*(2*x+1)/3 + 2*x*(x+1) + 4*x
	// we also need to add 1 for the first 'square'
	// let S=2*x*(x+1)
	// Sumtotal = 4*S*(2*x+1)/3 + S + 4*x + 1
	uint64_t x = n / 2;
	const uint64_t m = 1000000007;
	x %= m;
	uint64_t s = 2 * x * (x + 1) % m;
	uint64_t sum = ( (4*s*(2*x+1)) % m ) * InverseModulo((uint64_t)3, m);
	sum = (sum % m + s % m + (4 * x + 1) % m) % m;
	return sum;
}

void P028_NumberSpiralDiagonals::main()
{
	std::ios_base::sync_with_stdio(false);

	int32_t T;
	std::cin >> T;
	for (int32_t ii = 0; ii < T; ++ii)
	{
		uint64_t n;
		std::cin >> n;
		std::cout << Solve(n) << "\n";
	}
}
