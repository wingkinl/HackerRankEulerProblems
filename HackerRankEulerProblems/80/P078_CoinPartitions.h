#ifndef HACKERRANK_EULER_078_H_
#define HACKERRANK_EULER_078_H_

#include <vector>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler078/problem

struct P078_CoinPartitions
{
	P078_CoinPartitions(int max = 1000);

	static int SolveSlow(int n);

	int Solve(int n);

	static void main();
private:
	std::vector<int>	partitions_;
};

#endif // HACKERRANK_EULER_078_H_
