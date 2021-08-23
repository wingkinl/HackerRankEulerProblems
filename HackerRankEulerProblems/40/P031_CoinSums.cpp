#include "P031_CoinSums.h"
#include <iostream>
#include "libs/numeric.h"

static const int32_t kCoins[] = { 1, 2, 5, 10, 20, 50, 100, 200 };

// https://www.mathblog.dk/project-euler-31-combinations-english-currency-denominations/
void P031_CoinSums::Init(int32_t max_coin)
{
	number_of_ways.resize(max_coin + 1);
	number_of_ways[0] = 1;

	for (int ii = 0; ii < _countof(kCoins); ii++)
	{
		for (int jj = kCoins[ii]; jj <= max_coin; jj++)
		{
			number_of_ways[jj] += number_of_ways[jj - kCoins[ii]] % 1000000007;
		}
	}
}

uint64_t P031_CoinSums::Solve(int32_t n)
{
	return number_of_ways[n] % 1000000007;
}

void P031_CoinSums::main()
{
	std::ios_base::sync_with_stdio(false);

	int32_t T;
	std::cin >> T;
	std::vector<int32_t> vn(T);
	int32_t max_coin = 0;
	for (int32_t ii = 0; ii < T; ++ii)
	{
		std::cin >> vn[ii];
		if (vn[ii] > max_coin)
			max_coin = vn[ii];
	}
	P031_CoinSums p;
	p.Init(max_coin);
	for (auto& n : vn)
	{
		std::cout << p.Solve(n) << "\n";
	}
}
