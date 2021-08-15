#ifndef LIBS_NUMERIC_H_
#define LIBS_NUMERIC_H_

// C++17
#if __cplusplus >= 201703L
#include <numeric>
#endif

namespace hackerrank_euler
{
#if __cplusplus >= 201703L	// C++17
	using std::gcd;
	using std::lcm;
#else
	// https://en.wikipedia.org/wiki/Greatest_common_divisor
	template <typename T>
	T gcd(T a, T b)
	{
		T d = 0;
		while (a != b)
		{
			if (b > a)
				std::swap(a, b);
			if (!(a & 1) || !(b & 1))
			{
				if (!(a & 1))
				{
					a >>= 1;
					if (!(b & 1))
					{
						b >>= 1;
						++d;
					}
				}
				else
					b >>= 1;
			}
			else
			{
				a = (a - b) >> 1;
			}
		}
		return a * (1 << d);
	}

	// https://en.wikipedia.org/wiki/Least_common_multiple
	template <typename T>
	T lcm(T a, T b)
	{
		return (a * b) / gcd(a, b);
	}
#endif	// #if __cplusplus >= 201703L

	// https://www.geeksforgeeks.org/square-root-of-an-integer/
	template <typename T>
	T FloorSqrt(T x)
	{
		// Base cases
		if (x == 0 || x == 1)
			return x;

		// Do Binary Search for floor(sqrt(x))
		T start = 0, end = x / 2, ans;
		while (start <= end) {
			auto mid = (start + end) / 2;

			// If x is a perfect square
			if (mid * mid == x)
				return mid;
			if (mid <= x / mid) {
				start = mid + 1;
				ans = mid;
			}
			else // If mid*mid is greater than x
				end = mid - 1;
		}
		return ans;
	}
}

#endif // LIBS_NUMERIC_H_
