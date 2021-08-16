#ifndef HACKERRANK_EULER_023_H_
#define HACKERRANK_EULER_023_H_

#include <cstdint>
#include <set>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler023/problem

struct P023_NonAbundantSums
{
	void Init(uint32_t n);

	bool Solve(uint32_t n);

	static void main();
private:
	uint32_t			max_num = 0;
	std::set<uint32_t>	abundant;
};

#endif // HACKERRANK_EULER_022_H_
