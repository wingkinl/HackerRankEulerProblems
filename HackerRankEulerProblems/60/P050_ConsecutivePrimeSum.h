#ifndef HACKERRANK_EULER_050_H_
#define HACKERRANK_EULER_050_H_

#include <cstdint>
#include <vector>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler050/problem

struct P050_ConsecutivePrimeSum
{
	struct Result
	{
		uint64_t	min_prime_with_max_len;
		uint32_t	max_consecutive_len;
		uint64_t	prime_start;
	};

	P050_ConsecutivePrimeSum(uint64_t prime_upper_bound);

	Result Solve(uint64_t max_prime);

	static void main();
private:
	std::vector<uint64_t>	primes_;
	std::vector<uint64_t>	prime_sums_;
};

#endif // HACKERRANK_EULER_050_H_
