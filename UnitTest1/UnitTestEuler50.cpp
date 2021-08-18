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
#include "../HackerRankEulerProblems/20/P015_LatticePaths.h"
#include "../HackerRankEulerProblems/20/P016_PowerDigitSum.h"
#include "../HackerRankEulerProblems/20/P017_NumberToWords.h"
#include "../HackerRankEulerProblems/20/P018_MaximumPathSumI.h"
#include "../HackerRankEulerProblems/20/P019_CountingSundays.h"
#include "../HackerRankEulerProblems/20/P020_FactorialDigitSum.h"
#include "../HackerRankEulerProblems/40/P021_AmicableNumbers.h"
#include "../HackerRankEulerProblems/40/P022_NamesScores.h"
#include "../HackerRankEulerProblems/40/P023_NonAbundantSums.h"
#include "../HackerRankEulerProblems/40/P024_LexicographicPermutations.h"
#include "../HackerRankEulerProblems/40/P025_NdigitFibonacciNumber.h"
#include "../HackerRankEulerProblems/40/P026_ReciprocalCycles.h"
#include "../HackerRankEulerProblems/40/P027_QuadraticPrimes.h"
#include "../HackerRankEulerProblems/40/P028_NumberSpiralDiagonals.h"
#include "../HackerRankEulerProblems/40/P029_DistinctPowers.h"
#include "../HackerRankEulerProblems/40/P030_DigitNthPowers.h"
#include "../HackerRankEulerProblems/40/P031_CoinSums.h"
#include "../HackerRankEulerProblems/40/P032_PandigitalProducts.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template <>
			static std::wstring ToString<std::pair<int, int>>(const std::pair<int, int>& q)
			{
				std::wstringstream ss;
				ss << q.first << ", " << q.second;
				return ss.str();
			}
		}
	}
}

namespace UnitTestEuler
{
	TEST_CLASS(UnitTestEuler001)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(23ULL, P001_MultiplesOf3And5::Solve(10));
			Assert::AreEqual(2318ULL, P001_MultiplesOf3And5::Solve(100));
		}
	};

	TEST_CLASS(UnitTestEuler002)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(10ULL, P002_SumOfEvenFibonacciNumbers::Solve(10));
			Assert::AreEqual(44ULL, P002_SumOfEvenFibonacciNumbers::Solve(100));
		}
	};

	TEST_CLASS(UnitTestEuler003)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(5ULL, P003_LargestPrimeFactor::Solve(10));
			Assert::AreEqual(17ULL, P003_LargestPrimeFactor::Solve(17));
			Assert::AreEqual(29ULL, P003_LargestPrimeFactor::Solve(13195));
		}
	};

	TEST_CLASS(UnitTestEuler004)
	{
	public:
		TEST_METHOD(Test)
		{
			P004_LargestPalindromeProduct p;
			Assert::AreEqual(101101, p.Solve(101110));
			Assert::AreEqual(793397, p.Solve(800000));
		}
	};

	TEST_CLASS(UnitTestEuler005)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(6, P005_SmallestMultiple::Solve(3));
			Assert::AreEqual(2520, P005_SmallestMultiple::Solve(10));
		}
	};

	TEST_CLASS(UnitTestEuler006)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(22L, P006_SumSquareDifference::Solve(3L));
			Assert::AreEqual(2640L, P006_SumSquareDifference::Solve(10L));
		}
	};

	TEST_CLASS(UnitTestEuler007)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(5, P007_10001stPrime::Solve(3));
			Assert::AreEqual(13, P007_10001stPrime::Solve(6));
		}
	};

	TEST_CLASS(UnitTestEuler008)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(3150, P008_LargestProductInASeries::Solve("3675356291", 5));
			Assert::AreEqual(0, P008_LargestProductInASeries::Solve("2709360626", 5));
		}
	};

	TEST_CLASS(UnitTestEuler009)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(60, P009_SpecialPythagoreanTriplet::Solve(12));
			Assert::AreEqual(-1, P009_SpecialPythagoreanTriplet::Solve(4));
		}
	};

	TEST_CLASS(UnitTestEuler010)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(10L, P010_SummationOfPrimes::Solve(5));
			Assert::AreEqual(17L, P010_SummationOfPrimes::Solve(10));
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
			Assert::AreEqual(73812150L, P011_LargestProductInAGrid::Solve(grid));
		}
	};

	TEST_CLASS(UnitTestEuler012)
	{
	public:
		TEST_METHOD(Test)
		{
			P012_HighlyDivisibleTriangularNumber p;
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
			P013_LargeSum p;
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
			P014_LongestCollatzSequence p;
			Assert::AreEqual(9ULL, p.Solve(10ULL));
			Assert::AreEqual(9ULL, p.Solve(15ULL));
			Assert::AreEqual(19ULL, p.Solve(20ULL));
		}
	};

	TEST_CLASS(UnitTestEuler015)
	{
	public:
		TEST_METHOD(Test)
		{
			P015_LatticePaths p;
			Assert::AreEqual(6U, p.Solve(2, 2));
			Assert::AreEqual(10U, p.Solve(3, 2));
		}
	};

	TEST_CLASS(UnitTestEuler016)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(8ULL, P016_PowerDigitSum::Solve(3));
			Assert::AreEqual(7ULL, P016_PowerDigitSum::Solve(4));
			Assert::AreEqual(11ULL, P016_PowerDigitSum::Solve(7));
		}
	};

	TEST_CLASS(UnitTestEuler017)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(std::string("Ten"), P017_NumberToWords::Solve(10ULL));
			Assert::AreEqual(std::string("Seventeen"), P017_NumberToWords::Solve(17ULL));
			Assert::AreEqual(std::string("One Hundred Four Billion Three Hundred "
				"Eighty Two Million Four Hundred Twenty Six Thousand One Hundred Twelve"), 
				P017_NumberToWords::Solve(104382426112ULL));
		}
	};

	TEST_CLASS(UnitTestEuler018)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(23, P018_MaximumPathSumI::Solve({
				3,
				7,4,
				2,4,6,
				8,5,9,3
				}));
		}
	};

	TEST_CLASS(UnitTestEuler019)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(18, P019_CountingSundays::Solve({1900,1,1}, {1910,1,1}));
			Assert::AreEqual(35, P019_CountingSundays::Solve({2000,1,1}, {2020,1,1}));
		}
	};

	TEST_CLASS(UnitTestEuler020)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(6ULL, P020_FactorialDigitSum::Solve(3));
			Assert::AreEqual(9ULL, P020_FactorialDigitSum::Solve(6));
			Assert::AreEqual(27ULL, P020_FactorialDigitSum::Solve(10));
		}
	};

	TEST_CLASS(UnitTestEuler021)
	{
	public:
		TEST_METHOD(Test)
		{
			P021_AmicableNumbers p;
			Assert::AreEqual(504ULL, p.Solve(300));
			Assert::AreEqual(2898ULL, p.Solve(2000));
		}
	};

	TEST_CLASS(UnitTestEuler022)
	{
	public:
		TEST_METHOD(Test)
		{
			P022_NamesScores p({"ALEX", "LUIS","JAMES","BRIAN","PAMELA"});
			Assert::AreEqual(240U, p.Solve("PAMELA"));
		}
	};

	TEST_CLASS(UnitTestEuler023)
	{
	public:
		TEST_METHOD(Test)
		{
			P023_NonAbundantSums p;
			Assert::IsTrue(p.Solve(24));
			Assert::IsFalse(p.Solve(49));
		}
	};

	TEST_CLASS(UnitTestEuler024)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(std::string("abcdefghijklm"), P024_LexicographicPermutations::Solve(1));
			Assert::AreEqual(std::string("abcdefghijkml"), P024_LexicographicPermutations::Solve(2));
			Assert::AreEqual(std::string("mgdfeibclkjha"), P024_LexicographicPermutations::Solve(6000000000));
		}
	};

	TEST_CLASS(UnitTestEuler025)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(12LL, P025_NdigitFibonacciNumber::Solve(3));
			Assert::AreEqual(17LL, P025_NdigitFibonacciNumber::Solve(4));
			Assert::AreEqual(45LL, P025_NdigitFibonacciNumber::Solve(10));
		}
	};

	TEST_CLASS(UnitTestEuler026)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(3, P026_ReciprocalCycles::Solve(5));
			Assert::AreEqual(7, P026_ReciprocalCycles::Solve(10));
		}
	};

	TEST_CLASS(UnitTestEuler027)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(std::make_pair<int,int>(-1,41), P027_QuadraticPrimes::Solve(42));
		}
	};

	TEST_CLASS(UnitTestEuler028)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(25ULL, P028_NumberSpiralDiagonals::Solve(3ULL));
			Assert::AreEqual(101ULL, P028_NumberSpiralDiagonals::Solve(5ULL));
		}
	};

	TEST_CLASS(UnitTestEuler029)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(15ULL, P029_DistinctPowers::Solve(5));
			Assert::AreEqual(9981236306ULL, P029_DistinctPowers::Solve(100000));
		}
	};

	TEST_CLASS(UnitTestEuler030)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(19316, P030_DigitNthPowers::Solve(4));
		}
	};

	TEST_CLASS(UnitTestEuler031)
	{
	public:
		TEST_METHOD(Test)
		{
			P031_CoinSums p;
			p.Init(20);
			Assert::AreEqual(11ULL, p.Solve(10));
			Assert::AreEqual(22ULL, p.Solve(15));
			Assert::AreEqual(41ULL, p.Solve(20));
		}
	};

	TEST_CLASS(UnitTestEuler032)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(12U, P032_PandigitalProducts::Solve(4));
		}
	};
}
