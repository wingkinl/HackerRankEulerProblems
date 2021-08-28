#ifndef HACKERRANK_EULER_045_H_
#define HACKERRANK_EULER_045_H_

#include <vector>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler045/problem

struct P045_TriangularPentagonalHexagonal
{
	using Results = std::vector<uint64_t>;

	static Results Solve(uint64_t max, uint32_t a, uint32_t b);

	static void main();
};

#endif // HACKERRANK_EULER_045_H_
