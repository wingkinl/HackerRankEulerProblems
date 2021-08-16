#ifndef HACKERRANK_EULER_021_H_
#define HACKERRANK_EULER_021_H_

#include <cstdint>
#include <vector>
#include <set>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler021/problem

struct P021_AmicableNumbers 
{
	uint64_t Solve(uint32_t n);

	void Init(uint32_t n);

	static void main();
private:
	struct AmicableNumInfo
	{
		bool has_amicable;
		std::set<uint32_t> pairs;
	};
	std::vector<AmicableNumInfo> amicable_num_info;
};

#endif // HACKERRANK_EULER_021_H_
