#include "pch.h"
#include "CppUnitTest.h"
#include "../HackerRankEulerProblems/20/P001_MultiplesOf3And5.h"
#include "../HackerRankEulerProblems/20/P002_SumOfEvenFibonacciNumbers.h"
#include "../HackerRankEulerProblems/20/P003_LargestPrimeFactor.h"
#include "../HackerRankEulerProblems/20/P004_LargestPalindromeProduct.h"
#include "../HackerRankEulerProblems/20/P005_SmallestMultiple.h"
#include "../HackerRankEulerProblems/20/P006_SumSquareDifference.h"
#include "../HackerRankEulerProblems/20/P007_10001stPrime.h"
#include "../HackerRankEulerProblems/20/P008_LargestProductInASeries.h"
#include "../HackerRankEulerProblems/20/P009_SpecialPythagoreanTriplet.h"
#include "../HackerRankEulerProblems/20/P010_SummationOfPrimes.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestEuler
{
	TEST_CLASS(UnitTestEuler001)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(23ULL, P001MultiplesOf3And5::Solve(10));
			Assert::AreEqual(2318ULL, P001MultiplesOf3And5::Solve(100));
		}
	};

	TEST_CLASS(UnitTestEuler002)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(10ULL, P002SumOfEvenFibonacciNumbers::Solve(10));
			Assert::AreEqual(44ULL, P002SumOfEvenFibonacciNumbers::Solve(100));
		}
	};

	TEST_CLASS(UnitTestEuler003)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(5ULL, P003LargestPrimeFactor::Solve(10));
			Assert::AreEqual(17ULL, P003LargestPrimeFactor::Solve(17));
			Assert::AreEqual(29ULL, P003LargestPrimeFactor::Solve(13195));
		}
	};

	TEST_CLASS(UnitTestEuler004)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(101101, P004LargestPalindromeProduct::Solve(101110));
			Assert::AreEqual(793397, P004LargestPalindromeProduct::Solve(800000));
		}
	};

	TEST_CLASS(UnitTestEuler005)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(6, P005SmallestMultiple::Solve(3));
			Assert::AreEqual(2520, P005SmallestMultiple::Solve(10));
		}
	};

	TEST_CLASS(UnitTestEuler006)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(22L, P006SumSquareDifference::Solve(3L));
			Assert::AreEqual(2640L, P006SumSquareDifference::Solve(10L));
		}
	};

	TEST_CLASS(UnitTestEuler007)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(5, P00710001stPrime::Solve(3));
			Assert::AreEqual(13, P00710001stPrime::Solve(6));
		}
	};

	TEST_CLASS(UnitTestEuler008)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(3150, P008LargestProductInASeries::Solve("3675356291", 5));
			Assert::AreEqual(0, P008LargestProductInASeries::Solve("2709360626", 5));
		}
	};

	TEST_CLASS(UnitTestEuler009)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(60, P009SpecialPythagoreanTriplet::Solve(12));
			Assert::AreEqual(-1, P009SpecialPythagoreanTriplet::Solve(4));
		}
	};

	TEST_CLASS(UnitTestEuler010)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(10L, P010SummationOfPrimes::Solve(5));
			Assert::AreEqual(17L, P010SummationOfPrimes::Solve(10));
		}
	};
}
