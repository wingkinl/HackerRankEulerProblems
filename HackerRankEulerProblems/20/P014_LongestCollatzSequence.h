#ifndef HACKERRANK_EULER_014_H_
#define HACKERRANK_EULER_014_H_

#include <vector>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler014/problem

struct P014LongestCollatzSequence
{
	uint64_t Solve(uint64_t n);

	static void main();
private:
	uint64_t GetTermStep(uint64_t term);

	enum { kMaximum = 5000000 };

	std::vector<uint64_t> term_steps;
	std::vector<uint64_t> max_step_nums;
};

#endif // HACKERRANK_EULER_014_H_
