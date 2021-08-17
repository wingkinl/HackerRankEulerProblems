#include "P024_LexicographicPermutations.h"
#include <iostream>

#ifndef _countof
	#define _countof(_Array) (sizeof(_Array) / sizeof(_Array[0]))
#endif // _countof

std::string P024_LexicographicPermutations::Solve(uint64_t n)
{
	// First see an simpler example "abcd", and here's the alphabetically
	// ordered result:
	//  0=abcd  1=abdc  2=acbd  3=acdb  4=adbc  5=adcb
	//  6=bacd  7=badc  8=bcad  9=bcda 10=bdac 11=bdca
	// 12=cabd 13=cadb 14=cbad 15=cbda 16=cdab 17=cdba
	// 18=dabc 19=dacb 20=dbac 21=dbca 22=dcab 23=dcba
	//
	// For every position of the result string, the ith char is picked 
	// according to the factorial number (len-i-1)!.
	// For example, when deciding the first char, if the index is 20,
	// factorial number is 3! = 6, 6 is also how many results in a "row"
	// or a group for permutations that starts with each letter.
	// Divide 20 by 6, we get 3 (remainder is 2), so it's the 4th letter.
	// we shift/rotate it to the first (so we get 18=dabc), then consider
	// how to arrange the rest (abc) and apply similar logic with the 
	// remainder number (which is 2) and its corresponding factorial.
	std::string str = "abcdefghijklm";
	static const uint64_t kFactorials[] = {1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
	for (int f = _countof(kFactorials)-1; f >= 0; --f)
	{
		if (n > kFactorials[f])
		{
			auto dd = lldiv(n-1, kFactorials[f]);
			const size_t begin = str.length() - 1 - (f+1);
			const size_t pos = begin + (size_t)dd.quot;
			std::rotate(str.begin()+begin, str.begin()+pos, str.begin()+pos+1);
			if (dd.rem)
			{
				n = (uint64_t)dd.rem+1;
			}
			else
				break;
		}
	}
	return str;
}

void P024_LexicographicPermutations::main()
{
	std::ios_base::sync_with_stdio(false);

	uint32_t T;
	std::cin >> T;
	for (uint32_t ii = 0; ii < T; ++ii)
	{
		uint64_t n;
		std::cin >> n;
		std::cout << Solve(n) << std::endl;
	}
}
