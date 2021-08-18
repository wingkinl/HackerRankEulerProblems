#ifndef HACKERRANK_EULER_031_H_
#define HACKERRANK_EULER_031_H_

#include <cstdint>
#include <vector>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler031/problem

struct P031_CoinSums
{
	void Init(int32_t max_coin);

	uint64_t Solve(int32_t n);

	static void main();
private:
	std::vector<uint64_t> number_of_ways;
};

#endif // HACKERRANK_EULER_031_H_
