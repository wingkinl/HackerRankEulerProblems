#ifndef HACKERRANK_EULER_012_H_
#define HACKERRANK_EULER_012_H_
#include <vector>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler012/problem

struct P012HighlyDivisibleTriangularNumber
{
	int Solve(int n);

	static void main();
private:
	std::vector<std::pair<int, int>> tri_divisors;
	int known_max_divisor = 1;
};

#endif // HACKERRANK_EULER_012_H_
