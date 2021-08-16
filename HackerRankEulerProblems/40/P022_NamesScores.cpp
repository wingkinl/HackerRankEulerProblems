#include "P022_NamesScores.h"
#include <iostream>
#include <algorithm>

P022_NamesScores::P022_NamesScores(const std::vector<std::string>& vs)
{
	names = vs;
	std::stable_sort(names.begin(), names.end());
}

uint32_t P022_NamesScores::Solve(const std::string& str)
{
	auto it = std::find(names.begin(), names.end(), str);
	if (it == names.end())
		return 0;
	uint32_t score = 0;
	for (auto ch : str)
	{
		score += ch - (ch >= 'a' ? 'a' : 'A') + 1;
	}
	score *= (uint32_t)std::distance(names.begin(), it) + 1;
	return score;
}

void P022_NamesScores::main()
{
	std::ios_base::sync_with_stdio(false);
	uint32_t n;
	std::cin >> n;
	std::vector<std::string> vs(n);
	for (uint32_t ii = 0; ii < n; ++ii)
	{
		std::cin >> vs[ii];
	}
	P022_NamesScores p(vs);
	uint32_t q;
	std::cin >> q;
	for (uint32_t qq = 0; qq < q; ++qq)
	{
		std::string str;
		std::cin >> str;
		std::cout << p.Solve(str) << std::endl;
	}
}
