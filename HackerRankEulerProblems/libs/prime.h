#ifndef LIBS_PRIME_H_
#define LIBS_PRIME_H_

#include <vector>
#include "numeric.h"

namespace hackerrank_euler
{
	template <typename T>
	bool IsPrime(T n)
	{
		// Corner case
		if (n <= 1)
			return false;
		// Check from 2 to square root of n
		const T kMax = (T)sqrt(n);
		for (T ii = 2; ii <= kMax; ++ii)
			if (n % ii == 0)
				return false;
		return true;
	}

	// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
	template <typename T>
	struct PrimeNumbers
	{
		void InitPrimes(T N)
		{
			prime_flags.resize(N + 1, true);

			prime_flags[0] = prime_flags[1] = false;
			const T kMaxNumToCheck = FloorSqrt(N);
			for (T ii = 2; ii <= kMaxNumToCheck; ++ii)
			{
				if (prime_flags[ii])
				{
					for (T jj = ii + ii; jj <= N; jj += ii)
						prime_flags[jj] = false;
				}
			}
			nums.resize(N);
			size_t count = 0;
			for (T ii = 2; ii <= N; ++ii)
			{
				if (prime_flags[ii])
					nums[count++] = ii;
			}
			nums.resize(count);
		}
		std::vector<T>			nums;
		std::vector<uint8_t>	prime_flags;
	};
}

#endif // LIBS_PRIME_H_