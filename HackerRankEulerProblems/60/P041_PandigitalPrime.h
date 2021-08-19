#ifndef HACKERRANK_EULER_041_H_
#define HACKERRANK_EULER_041_H_

#include <vector>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler041/problem

struct P041_PandigitalPrime
{
	P041_PandigitalPrime(int max);

	int Solve(int n);

	static void main();
private:
	std::vector<int> pandigital_primes;
};

#endif // HACKERRANK_EULER_041_H_
