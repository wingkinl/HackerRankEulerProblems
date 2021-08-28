#ifndef HACKERRANK_EULER_044_H_
#define HACKERRANK_EULER_044_H_

#include <vector>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler044/problem

struct P044_PentagonNumbers
{
	using Results = std::vector<uint64_t>;

	static Results Solve(uint32_t max, uint32_t offset);

	static void main();
};

#endif // HACKERRANK_EULER_044_H_
