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
#include "../HackerRankEulerProblems/20/P011_LargestProductInAGrid.h"
#include "../HackerRankEulerProblems/20/P012_HighlyDivisibleTriangularNumber.h"
#include "../HackerRankEulerProblems/20/P013_LargeSum.h"
#include "../HackerRankEulerProblems/20/P014_LongestCollatzSequence.h"


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

	TEST_CLASS(UnitTestEuler011)
	{
	public:
		TEST_METHOD(Test)
		{
			const int grid[20][20] =
			{
				{89,90,95,97,38,15,00,40,00,75,04,05,07,78,52,12,50,77,91, 8},
				{49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,04,56,62,00},
				{81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,03,49,13,36,65},
				{52,70,95,23,04,60,11,42,69,24,68,56,01,32,56,71,37,02,36,91},
				{22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80},
				{24,47,32,60,99,03,45,02,44,75,33,53,78,36,84,20,35,17,12,50},
				{32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70},
				{67,26,20,68,02,62,12,20,95,63,94,39,63, 8,40,91,66,49,94,21},
				{24,55,58,05,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72},
				{21,36,23, 9,75,00,76,44,20,45,35,14,00,61,33,97,34,31,33,95},
				{78,17,53,28,22,75,31,67,15,94,03,80,04,62,16,14, 9,53,56,92},
				{16,39,05,42,96,35,31,47,55,58,88,24,00,17,54,24,36,29,85,57},
				{86,56,00,48,35,71,89,07,05,44,44,37,44,60,21,58,51,54,17,58},
				{19,80,81,68,05,94,47,69,28,73,92,13,86,52,17,77,04,89,55,40},
				{04,52, 8,83,97,35,99,16,07,97,57,32,16,26,26,79,33,27,98,66},
				{88,36,68,87,57,62,20,72,03,46,33,67,46,55,12,32,63,93,53,69},
				{04,42,16,73,38,25,39,11,24,94,72,18, 8,46,29,32,40,62,76,36},
				{20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74,04,36,16},
				{20,73,35,29,78,31,90,01,74,31,49,71,48,86,81,16,23,57,05,54},
				{01,70,54,71,83,51,54,69,16,92,33,48,61,43,52,01,89,19,67,48}
			};
			Assert::AreEqual(73812150L, P011LargestProductInAGrid::Solve(grid));
		}
	};

	TEST_CLASS(UnitTestEuler012)
	{
	public:
		TEST_METHOD(Test)
		{
			P012HighlyDivisibleTriangularNumber p;
			Assert::AreEqual(3, p.Solve(1));
			Assert::AreEqual(6, p.Solve(2));
			Assert::AreEqual(6, p.Solve(3));
			Assert::AreEqual(28, p.Solve(4));
			Assert::AreEqual(28, p.Solve(5));
		}
	};

	TEST_CLASS(UnitTestEuler013)
	{
	public:
		TEST_METHOD(Test)
		{
			P013LargeSum p;
			const std::vector<std::string> vs = {
				"37107287533902102798797998220837590246510135740250",
				"46376937677490009712648124896970078050417018260538",
				"74324986199524741059474233309513058123726617309629",
				"91942213363574161572522430563301811072406154908250",
				"23067588207539346171171980310421047513778063246676"
			};
			Assert::AreEqual(std::string("2728190129"), p.Solve(vs));
		}
	};

	TEST_CLASS(UnitTestEuler014)
	{
	public:
		TEST_METHOD(Test)
		{
			P014LongestCollatzSequence p;
			Assert::AreEqual(9ULL, p.Solve(10ULL));
			Assert::AreEqual(9ULL, p.Solve(15ULL));
			Assert::AreEqual(19ULL, p.Solve(20ULL));
		}
	};
}
