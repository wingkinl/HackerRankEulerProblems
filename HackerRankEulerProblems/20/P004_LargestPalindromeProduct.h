#ifndef HACKERRANK_EULER_004_H_
#define HACKERRANK_EULER_004_H_
#include <vector>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler004/problem

struct P004_LargestPalindromeProduct
{
	int Solve(int n);

	static void main();
private:
	void InitPalindrome();
private:
	std::vector<int> all_palindromes;
};

#endif // HACKERRANK_EULER_004_H_
