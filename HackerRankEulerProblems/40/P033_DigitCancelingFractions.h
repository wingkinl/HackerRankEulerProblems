#ifndef HACKERRANK_EULER_033_H_
#define HACKERRANK_EULER_033_H_

#include <unordered_set>
#include <utility>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler033/problem

struct FractionContext;

struct P033_DigitCancelingFractions
{
	P033_DigitCancelingFractions(int32_t digits, int32_t cancel);

	std::pair<int64_t, int64_t> GetResult() const;

	static void main();
private:
	const int32_t kDigits;
	const int32_t kCancel;
	const int32_t kKeep;

	int64_t numerator_sum = 0;
	int64_t denominator_sum = 0;

	std::unordered_set<int32_t> match_numbers;
private:
	void CheckCancelDigits(FractionContext& ctxt);
};

#endif // HACKERRANK_EULER_033_H_
