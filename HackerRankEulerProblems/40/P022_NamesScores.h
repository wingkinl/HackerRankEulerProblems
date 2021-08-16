#ifndef HACKERRANK_EULER_022_H_
#define HACKERRANK_EULER_022_H_

#include <cstdint>
#include <vector>
#include <string>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler022/problem

struct P022_NamesScores
{
	P022_NamesScores(const std::vector<std::string>& vs);

	uint32_t Solve(const std::string& str);

	static void main();
private:
	std::vector<std::string> names;
};

#endif // HACKERRANK_EULER_022_H_
