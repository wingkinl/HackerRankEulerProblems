#ifndef HACKERRANK_EULER_033_H_
#define HACKERRANK_EULER_033_H_

#include <unordered_set>
#include <utility>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler033/problem

struct P033_DigitCancelingFractions
{
	P033_DigitCancelingFractions(int32_t digits, int32_t cancel);

	std::pair<int64_t, int64_t> GetResult() const;

	static void main();
private:
	const int32_t kDigits;
	const int32_t kCancel;
	const int32_t kKeep;

	int64_t numeratorSum = 0;
	int64_t denominatorSum = 0;

	typedef int32_t    DigitT;
	typedef int16_t    PosT;

	struct Number
	{
		int32_t digits_count = 0;
		DigitT	digits[4] = { 0 };

		void Increase();
	};

	struct CombinedNumber
	{
		CombinedNumber(int32_t digits, int32_t cancel);

		inline bool Next();

		int32_t Combine(const Number& num2, const DigitT(&cancel_digits)[3]);

		int32_t digits_count = 0;
		int32_t cancel = 0;
		DigitT	digits[4] = { 0 };
		// zeros are digits to be kept, non-zeros are to be canceled
		PosT	digit_pos[4] = { 0 };
	};

	std::unordered_set<int32_t> match_numbers;
};

#endif // HACKERRANK_EULER_033_H_
