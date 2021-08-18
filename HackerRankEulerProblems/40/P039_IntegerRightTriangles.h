#ifndef HACKERRANK_EULER_039_H_
#define HACKERRANK_EULER_039_H_

#include <set>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler039/problem

struct P039_IntegerRightTriangles
{
	P039_IntegerRightTriangles(unsigned int max_perimeter);

	unsigned int Solve(unsigned int pp);

	static void main();
private:
	std::set<unsigned int> max_perimeters;
};

#endif // HACKERRANK_EULER_038_H_
