#include "P033_DigitCancelingFractions.h"
#include <iostream>
#include "libs/numeric.h"
#include <algorithm>

using namespace hackerrank_euler;

typedef int32_t    DigitT;
typedef int16_t    PosT;

struct NumberDigits
{
	int32_t digits_count = 0;
	DigitT	digits[4] = { 0 };

	void Increase();
};

struct CombinedNumber
{
	CombinedNumber(int32_t digits, int32_t cancel);

	inline bool Next();

	int32_t Combine(const NumberDigits& num2, const DigitT(&cancel_digits)[3]);

	int32_t digits_count = 0;
	int32_t cancel = 0;
	DigitT	digits[4] = { 0 };
	// zeros are digits to be kept, non-zeros are to be canceled
	PosT	digit_pos[4] = { 0 };
};

void NumberDigits::Increase()
{
	NextRepeatCombination(digits, digits + digits_count, 0, 9);
}

CombinedNumber::CombinedNumber(int32_t digits, int32_t cancel)
{
	this->digits_count = digits;
	this->cancel = cancel;
	for (int32_t ii = 0; ii < cancel; ++ii)
	{
		digit_pos[digits - cancel + ii] = ii + 1;
	}
}

bool CombinedNumber::Next()
{
	return std::next_permutation(digit_pos, digit_pos + digits_count);
}

int32_t CombinedNumber::Combine(const NumberDigits& num2, const DigitT(&cancel_digits)[3])
{
	int32_t keep = digits_count - cancel - 1; // non canceled
	int32_t result_num = 0;
	static const int32_t kDigitFactor[4] = { 1,10,100,1000 };
	DigitT digit;
	for (int32_t ii = digits_count - 1; ii >= 0; --ii)
	{
		auto pos = digit_pos[ii];
		if (pos == 0)
		{
			digit = num2.digits[keep--];
			// skip leading zero cases
			if (ii == digits_count - 1 && digit == 0)
				return 0;
		}
		else
		{
			digit = cancel_digits[pos - 1];
		}
		digits[ii] = digit;
		result_num += digit * kDigitFactor[ii];
	}
	return result_num;
}

struct FractionContext
{
	FractionContext(int32_t digits, int32_t cancel)
		: d1(digits, cancel)
		, n1(digits, cancel)
	{
	}

	CombinedNumber d1;
	CombinedNumber n1;

	NumberDigits d2_digits;
	NumberDigits n2_digits;

	int32_t	d2;
	int32_t n2;
};

P033_DigitCancelingFractions::P033_DigitCancelingFractions(int32_t digits, int32_t cancel)
	: kDigits(digits), kCancel(cancel), kKeep(kDigits - cancel)
{
	// n1 / d1 (original) = n2 / d2 (reduced)
	const int32_t kMaxD2s[] = { 9,99,999 };
	const int32_t kMaxD2 = kMaxD2s[kKeep - 1];

	FractionContext ctxt(kDigits, kCancel);
	ctxt.d2_digits = { kKeep, {1} };

	for (ctxt.d2 = 1; ctxt.d2 <= kMaxD2; ++ctxt.d2)
	{
		ctxt.n2_digits = { kKeep, {1} };
		for (ctxt.n2 = 1; ctxt.n2 < ctxt.d2; ++ctxt.n2)
		{
			CheckCancelDigits(ctxt);
			ctxt.n2_digits.Increase();
		}
		ctxt.d2_digits.Increase();
	}
}

void P033_DigitCancelingFractions::CheckCancelDigits(FractionContext& ctxt)
{
	DigitT cancel_digits[3] = { 1,1,1 };
	while (true)
	{
		do
		{
			auto d1 = ctxt.d1.Combine(ctxt.d2_digits, cancel_digits);
			if (d1 == 0)
				continue;
			do
			{
				auto n1 = ctxt.n1.Combine(ctxt.n2_digits, cancel_digits);
				if (n1 == 0)
					continue;
				// n1 / d1 = n2 / d2 -> n1 * d2 = d1 * n2
				if (n1 * ctxt.d2 == d1 * ctxt.n2)
				{
					auto ret = match_numbers.insert((n1 << 16) + d1);
					if (ret.second)
					{
						numerator_sum += n1;
						denominator_sum += d1;
					}
				}

			} while (ctxt.n1.Next());
		} while (ctxt.d1.Next());

		if (!NextRepeatCombination(cancel_digits, cancel_digits + kCancel, 1, 9))
			break;
	}
}

std::pair<int64_t, int64_t> P033_DigitCancelingFractions::GetResult() const
{
	return std::make_pair(numerator_sum, denominator_sum);
}

void P033_DigitCancelingFractions::main()
{
	std::ios_base::sync_with_stdio(false);

	int n = 2, k = 1;
	std::cin >> n >> k;
	P033_DigitCancelingFractions p(n, k);
	auto result = p.GetResult();
	std::cout << result.first << " " << result.second << "\n";
}

