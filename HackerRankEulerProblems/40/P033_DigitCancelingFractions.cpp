#include "P033_DigitCancelingFractions.h"
#include <iostream>
#include "libs/numeric.h"

using namespace hackerrank_euler;

P033_DigitCancelingFractions::P033_DigitCancelingFractions(int32_t digits, int32_t cancel)
	: kDigits(digits), kCancel(cancel), kKeep(kDigits - cancel)
{
	// n1 / d1 (original) = n2 / d2 (reduced)
	const int32_t kMaxD2s[] = { 9,99,999 };
	const int32_t kMaxD2 = kMaxD2s[kKeep - 1];

	CombinedNumber sd1(kDigits, kCancel);
	CombinedNumber sn1(kDigits, kCancel);

	Number sd2 = { kKeep, {1} };
	for (int32_t d2 = 1; d2 <= kMaxD2; ++d2)
	{
		Number sn2 = { kKeep, {1} };
		for (int32_t n2 = 1; n2 < d2; ++n2)
		{
			DigitT cancel_digits[3] = { 1,1,1 };
			while (true)
			{
				do
				{
					auto d1 = sd1.Combine(sd2, cancel_digits);
					if (d1 == 0)
						continue;
					do
					{
						auto n1 = sn1.Combine(sn2, cancel_digits);
						if (n1 == 0)
							continue;
						// n1 / d1 = n2 / d2 -> n1 * d2 = d1 * n2
						if (n1 * d2 == d1 * n2)
						{
							auto ret = match_numbers.insert((n1 << 16) + d1);
							if (ret.second)
							{
								numeratorSum += n1;
								denominatorSum += d1;
							}
						}

					} while (sn1.Next());
				} while (sd1.Next());

				if (!NextRepeatCombination(cancel_digits, cancel_digits + kCancel, 1, 9))
					break;
			}

			sn2.Increase();
		}
		sd2.Increase();
	}
}

std::pair<int64_t, int64_t> P033_DigitCancelingFractions::GetResult() const
{
	return std::make_pair(numeratorSum, denominatorSum);
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

void P033_DigitCancelingFractions::Number::Increase()
{
	NextRepeatCombination(digits, digits + digits_count, 0, 9);
}

P033_DigitCancelingFractions::CombinedNumber::CombinedNumber(int32_t digits, int32_t cancel)
{
	this->digits_count = digits;
	this->cancel = cancel;
	for (int32_t ii = 0; ii < cancel; ++ii)
	{
		digit_pos[digits - cancel + ii] = ii + 1;
	}
}

bool P033_DigitCancelingFractions::CombinedNumber::Next()
{
	return std::next_permutation(digit_pos, digit_pos + digits_count);
}

int32_t P033_DigitCancelingFractions::CombinedNumber::Combine(const Number& num2, const DigitT(&cancel_digits)[3])
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
