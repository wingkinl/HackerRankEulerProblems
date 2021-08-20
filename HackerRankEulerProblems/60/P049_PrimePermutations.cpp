#include "P049_PrimePermutations.h"
#include <iostream>
#include <map>
#include <algorithm>
#include "libs/numeric.h"

static inline uint64_t GetKeyForPrime(uint32_t prime)
{
	// The idea of generating a "key/signature" for a given prime
	// is borrowed from https://euler.stephan-brumme.com/49/
	uint64_t key = 0;
	const uint32_t kTens[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
	while (prime > 0)
	{
		auto dd = div(prime, 10);
		prime = dd.quot;
		key += kTens[dd.rem];
	}
	return key;
}

using KeyToPrimes = std::map<uint64_t, std::vector<uint32_t>>;

static void GetKeyToPrimes(KeyToPrimes& key_to_primes, uint32_t max_prime)
{
	const uint32_t kTens[] = {10,100,1000,10000,100000,1000000};
	// https://en.wikipedia.org/wiki/Prime-counting_function#Table_of_%CF%80(x),_x_/_log_x,_and_li(x)
	const uint32_t kMaxPrimeCount[] = {4,25,168,1229,9592,78498};
	auto max_prime_idx = std::distance(kTens, std::lower_bound(kTens, kTens+_countof(kTens), max_prime));
	auto max_prime_num = kTens[max_prime_idx];
	std::vector<uint8_t> prime_sieve((size_t)max_prime_num+1, true);
	prime_sieve[0] = prime_sieve[1] = false;

	const uint32_t kMaxNumToCheck = hackerrank_euler::FloorSqrt(max_prime_num);
	for (uint32_t ii = 2; ii <= kMaxNumToCheck; ++ii)
	{
		if (prime_sieve[ii])
		{
			for (uint32_t jj = ii + ii; jj <= max_prime_num; jj += ii)
				prime_sieve[jj] = false;
		}
	}

	// There are no arithmetic sequences made up of three 1-,2-,3- digit primes
	for (uint32_t num = 1001, jj = 0; num <= max_prime_num; ++num)
	{
		if (prime_sieve[num])
		{
			auto key = GetKeyForPrime(num);
			key_to_primes[key].push_back(num);
			++jj;
		}
	}
}

class APPrimePermutations
{
public:
	APPrimePermutations(const std::vector<uint32_t>& primes, uint32_t max_first_prime, 
		uint32_t sequence_size);
public:
	void FindAP(P049_PrimePermutations::Results& results);
private:
	void CalcDifferences();

	void CheckDiffs(P049_PrimePermutations::Results& results, size_t prime_idx, size_t count);
private:
	const std::vector<uint32_t>& primes_;
	const uint32_t max_first_prime_;
	const uint32_t sequence_size_;

	std::vector<std::pair<int32_t, uint32_t>> prime_diffs_;
	// Arithmetic progression sequence
	std::vector<uint16_t> ap_sequence_;
	std::vector<uint16_t> ap_sequence_count_;
	std::vector<uint16_t> next_primes_;
};

APPrimePermutations::APPrimePermutations(const std::vector<uint32_t>& primes, 
	uint32_t max_first_prime, uint32_t sequence_size)
	: primes_(primes)
	, max_first_prime_(max_first_prime)
	, sequence_size_(sequence_size)
{

}

void APPrimePermutations::FindAP(P049_PrimePermutations::Results& results)
{
	CalcDifferences();

	ap_sequence_.resize(prime_diffs_.size() + 1);
	ap_sequence_count_.resize(prime_diffs_.size() + 1);
	next_primes_.resize(prime_diffs_.size() + 1);

	size_t count = 0;
	int32_t cur_diff = 0;
	for (size_t ii = 0; ii < prime_diffs_.size(); ++ii)
	{
		auto& diff = prime_diffs_[ii];
		if (diff.first == cur_diff)
		{
			++count;
		}
		else
		{
			if (count >= sequence_size_-1)
			{
				CheckDiffs(results, ii-count, count);
			}
			int32_t small_prime_idx = (int32_t)(diff.second & 0x0000ffff);
			// since this is the first in a sequence, it must be the smallest 
			// (prime_diffs is sorted)
			// if even the smallest one is out of limit then it won't match
			if (primes_[small_prime_idx] >= max_first_prime_)
			{
				count = 0;
				cur_diff = 0;
				continue;
			}
			count = 1;
			cur_diff = diff.first;
		}
	}
	if (count >= sequence_size_ - 1)
	{
		CheckDiffs(results, prime_diffs_.size()-count, count);
	}
}

void APPrimePermutations::CalcDifferences()
{
	// The number of differences is 1+2+3+...(n-1)
	// so in total: (n-1)(1+n-1)/2 = n(n-1)/2
	// for each pair, the first is the difference, the second is the two indices of primes
	prime_diffs_.resize(primes_.size()*(primes_.size()-1)/2);
	size_t count = 0;
	for (size_t ii = 1; ii < primes_.size(); ++ii)
	{
		for (size_t jj = 0; jj < ii; ++jj)
		{
			auto& diff = prime_diffs_[count++];
			diff.first = primes_[ii] - primes_[jj];
			diff.second = (uint32_t)(((uint16_t)ii << 16) | (uint16_t)jj);
		}
	}
	std::stable_sort(prime_diffs_.begin(), prime_diffs_.end());
}

void APPrimePermutations::CheckDiffs(P049_PrimePermutations::Results& results, 
	size_t prime_idx, size_t count)
{
	std::fill(ap_sequence_.begin(), ap_sequence_.end(), 0);
	std::fill(ap_sequence_count_.begin(), ap_sequence_count_.end(), 0);

	uint16_t max_count = 0;
	for (size_t ii = 0; ii < count; ++ii)
	{
		auto& diff = prime_diffs_[prime_idx+ii];
		uint32_t small_prime_idx = (uint32_t)(diff.second & 0x0000ffff);
		uint32_t big_prime_idx = (uint32_t)(diff.second >> 16);
		uint16_t min_idx = ap_sequence_[small_prime_idx] ? ap_sequence_[small_prime_idx] : (uint16_t)(prime_idx+ii+1);
		ap_sequence_[small_prime_idx] = ap_sequence_[big_prime_idx] = min_idx;
		auto& sequence_count = ap_sequence_count_[min_idx-1];
		++sequence_count;
		if (sequence_count > max_count)
			max_count = sequence_count;

		next_primes_[small_prime_idx] = big_prime_idx;
	}
	if (max_count >= sequence_size_ - 1)
	{
		for (size_t ii = 0; ii < ap_sequence_count_.size(); ++ii)
		{
			if (ap_sequence_count_[ii] >= sequence_size_-1)
			{
				auto& diff = prime_diffs_[ii];
				uint32_t small_prime_idx = (uint32_t)(diff.second & 0x0000ffff);
				uint32_t min_prime = primes_[small_prime_idx];
				if (min_prime >= max_first_prime_)
					continue;

				std::vector<uint32_t> res_primes;
				res_primes.push_back(min_prime);

				uint32_t prev_prime_idx = small_prime_idx;
				for (uint16_t jj = 0; jj < ap_sequence_count_[ii]; ++jj)
				{
					uint32_t next_prime_idx = next_primes_[prev_prime_idx];
					prev_prime_idx = next_prime_idx;
					res_primes.push_back(primes_[next_prime_idx]);
					if (res_primes.size() == sequence_size_)
					{
						results.emplace_back(res_primes);
						res_primes.erase(res_primes.begin());
					}
				}
			}
		}
	}
}

auto P049_PrimePermutations::Solve(uint32_t max_first_prime, uint32_t sequence_size) -> Results
{
	Results results;
	results.reserve(50);

	KeyToPrimes key_to_primes;
	GetKeyToPrimes(key_to_primes, max_first_prime);

	for (auto& prime_pair : key_to_primes)
	{
		if (prime_pair.second.size() < sequence_size)
			continue;
		auto& primes = prime_pair.second;
		if (primes[0] >= max_first_prime)
			continue;

		APPrimePermutations ap(primes, max_first_prime, sequence_size);
		ap.FindAP(results);
	}
	std::stable_sort(results.begin(), results.end(), [](auto& left, auto& right){
		return left[0] < right[0];
		});
	return results;
}

void P049_PrimePermutations::main()
{
	std::ios_base::sync_with_stdio(false);

	uint32_t n = 2000, k = 3;
	std::cin >> n >> k;

	auto results = Solve(n, k);
	for (auto res : results)
	{
		for (auto v : res)
			std::cout << v;
		std::cout << "\n";
	}
}
