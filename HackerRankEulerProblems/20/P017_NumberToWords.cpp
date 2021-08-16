#include "P017_NumberToWords.h"
#include <iostream>
#include <sstream>

const static char* aNumWords20[] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine",
    "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
const static char* aNumWords10X[] = {"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
const static char* aNumWords1000X[] = {"","Thousand","Million","Billion","Trillion"};

#ifndef _countof
    #define _countof(_Array) (sizeof(_Array) / sizeof(_Array[0]))
#endif // _countof

std::string P017_NumberToWords::Solve(uint64_t n)
{
	if (n == 0)
		return "Zero";
	std::ostringstream ss;
	int64_t div_num = 1000000000000;
	std::string prefix = "";
	for (int ii = _countof(aNumWords1000X)-1; ii >= 0; --ii)
	{
		int64_t val = n / div_num % 1000;
		if (val)
		{
			auto dd = div((int)val, 100);
			if (dd.quot > 0)
			{
				ss << prefix << aNumWords20[dd.quot] << " Hundred";
				prefix = " ";
			}
			if (dd.rem >= 20)
			{
				ss << prefix << aNumWords10X[dd.rem / 10 - 2];
				if (dd.rem % 10)
					ss << ' ' << aNumWords20[dd.rem % 10];
				prefix = " ";
			}
			else if (dd.rem)
				ss << prefix << aNumWords20[dd.rem];
			if (aNumWords1000X[ii][0])
				ss << prefix << aNumWords1000X[ii];

			prefix = " ";
		}
		div_num /= 1000;
	}
	return ss.str();
}

void P017_NumberToWords::main()
{
	std::ios_base::sync_with_stdio(false);
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t)
	{
		uint64_t n;
		std::cin >> n;
		std::cout << Solve(n) << "\n";
	}
}
