#include "P050_ConsecutivePrimeSum.h"
#include <iostream>
#include <algorithm>
#include "libs/numeric.h"
#include "libs/prime.h"

P050_ConsecutivePrimeSum::P050_ConsecutivePrimeSum(uint64_t prime_upper_bound)
{
	// In fact, all the results start at small primes, so we
	// don't really need that many primes
	if (prime_upper_bound > 6000000ULL)
		prime_upper_bound = 6000000ULL;
	std::vector<uint8_t> prime_flags(prime_upper_bound + 1, true);
	prime_flags[0] = prime_flags[1] = false;
	const uint64_t kMaxNumToCheck = hackerrank_euler::FloorSqrt(prime_upper_bound);
	for (uint64_t ii = 2; ii <= kMaxNumToCheck; ++ii)
	{
		if (prime_flags[ii])
		{
			for (uint64_t jj = ii + ii; jj <= prime_upper_bound; jj += ii)
				prime_flags[jj] = false;
		}
	}
	primes_.resize(prime_upper_bound);
	prime_sums_.resize(prime_upper_bound + 1);
	prime_sums_[0] = 0;

	size_t count = 0;
	for (uint64_t ii = 2; ii <= prime_upper_bound; ++ii)
	{
		if (prime_flags[ii])
		{
			primes_[count] = ii;
			prime_sums_[count + 1] = prime_sums_[count] + primes_[count];
			++count;
		}
	}
	primes_.resize(count);
	prime_sums_.resize(count + 1);
}

auto P050_ConsecutivePrimeSum::Solve(uint64_t max_prime) -> Result
{
	auto it = std::lower_bound(prime_sums_.begin(), prime_sums_.end(), max_prime);
	auto dist = std::distance(prime_sums_.begin(), it);
	Result result = { 2, 1 };
	const auto kMaxLen = (uint32_t)dist;
	for (uint32_t len = kMaxLen; len >= 1; --len)
	{
		for (uint32_t ii = 0; ; ++ii)
		{
			uint64_t sum = prime_sums_[ii + len] - prime_sums_[ii];
			if (sum > max_prime)
				break;
			if (hackerrank_euler::IsPrime(sum))
			{
				// The first one must be the longest one, because
				// primes are only gonna get bigger
				result.min_prime_with_max_len = sum;
				result.max_consecutive_len = len;
				result.prime_start = primes_[ii];
				return result;
			}
		}
	}
	return result;
}

void P050_ConsecutivePrimeSum::main()
{
	std::ios_base::sync_with_stdio(false);

	uint32_t T = 1;
	std::cin >> T;
	std::vector<uint64_t> vn(T);
	std::vector<size_t> vn_idx(T);
	for (uint32_t ii = 0; ii < T; ++ii)
	{
		vn_idx[ii] = ii;
		auto& n = vn[ii];
		std::cin >> n;
	}
	std::stable_sort(vn_idx.begin(), vn_idx.end(),
		[&vn](auto left, auto right) {return vn[left] < vn[right]; });

	uint64_t max_n = vn[vn_idx.back()];
	
	P050_ConsecutivePrimeSum p(max_n);

	std::vector<Result> results(T);
	for (auto idx : vn_idx)
		results[idx] = p.Solve(vn[idx]);

	for (auto& result : results)
	{
		std::cout << result.min_prime_with_max_len << " " << result.max_consecutive_len << "\n";
		//std::cout << "starts at " << result.prime_start << std::endl;
	}
}
