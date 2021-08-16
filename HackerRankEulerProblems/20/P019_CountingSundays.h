#ifndef HACKERRANK_EULER_019_H_
#define HACKERRANK_EULER_019_H_
#include <cstdint>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler019/problem

struct P019_CountingSundays
{
	struct Date 
	{
		int64_t Y;
		int32_t m;
		int32_t d;
	};

	static int Solve(Date dt1, Date dt2);

	static void main();
};

#endif // HACKERRANK_EULER_019_H_
