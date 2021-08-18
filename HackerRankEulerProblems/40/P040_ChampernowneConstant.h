#ifndef HACKERRANK_EULER_040_H_
#define HACKERRANK_EULER_040_H_

#include <vector>
#include <cstdint>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler040/problem

struct P040_ChampernowneConstant
{
	P040_ChampernowneConstant();

	uint32_t Solve(const uint64_t (&digits)[7]);

	static void main();
private:
	std::vector<uint64_t> digit_bases;;
	std::vector<uint64_t> num_bases;
};

#endif // HACKERRANK_EULER_040_H_
