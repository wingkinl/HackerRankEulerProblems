#ifndef HACKERRANK_EULER_049_H_
#define HACKERRANK_EULER_049_H_

#include <cstdint>
#include <vector>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler049/problem

struct P049_PrimePermutations
{
	using Results = std::vector<std::vector<uint32_t>>;

	static Results Solve(uint32_t max_first_prime, uint32_t sequence_size);

	static void main();
};

#endif // HACKERRANK_EULER_049_H_
