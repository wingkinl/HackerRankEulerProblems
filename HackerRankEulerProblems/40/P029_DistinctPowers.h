#ifndef HACKERRANK_EULER_029_H_
#define HACKERRANK_EULER_029_H_

#include <cstdint>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler029/problem

struct P029_DistinctPowers
{
	static uint64_t Solve(int32_t n);

	static void main();
private:
	static int32_t CalcRepeatPower(int32_t n);
};

#endif // HACKERRANK_EULER_029_H_
