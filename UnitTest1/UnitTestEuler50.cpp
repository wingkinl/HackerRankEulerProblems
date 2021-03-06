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
#include "../HackerRankEulerProblems/40/P033_DigitCancelingFractions.h"
#include "../HackerRankEulerProblems/40/P034_DigitFactorials.h"
#include "../HackerRankEulerProblems/40/P035_CircularPrimes.h"
#include "../HackerRankEulerProblems/40/P036_DoubleBasePalindromes.h"
#include "../HackerRankEulerProblems/40/P037_TruncatablePrimes.h"
#include "../HackerRankEulerProblems/40/P038_PandigitalMultiples.h"
#include "../HackerRankEulerProblems/40/P039_IntegerRightTriangles.h"
#include "../HackerRankEulerProblems/40/P040_ChampernowneConstant.h"
#include "../HackerRankEulerProblems/60/P041_PandigitalPrime.h"
#include "../HackerRankEulerProblems/60/P042_CodedTriangleNumbers.h"
#include "../HackerRankEulerProblems/60/P043_SubStringDivisibility.h"
#include "../HackerRankEulerProblems/60/P044_PentagonNumbers.h"
#include "../HackerRankEulerProblems/60/P045_TriangularPentagonalHexagonal.h"
#include "../HackerRankEulerProblems/60/P046_GoldbachOtherConjecture.h"
#include "../HackerRankEulerProblems/60/P047_DistinctPrimesFactors.h"
#include "../HackerRankEulerProblems/60/P049_PrimePermutations.h"
#include "../HackerRankEulerProblems/60/P050_ConsecutivePrimeSum.h"


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

			template <>
			static std::wstring ToString<std::vector<uint64_t>>(const std::vector<uint64_t>& v)
			{
				std::wstringstream ss;
				for (auto n : v)
					ss << n;
				return ss.str();
			}

			template <>
			std::wstring ToString<std::vector<std::wstring>>(const std::vector<std::wstring>& vs)
			{
				std::wstring res;
				res.reserve(vs.size() * 4);
				for (auto& str : vs)
					res += str;
				return res;
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

	TEST_CLASS(UnitTestEuler033)
	{
	public:
		TEST_METHOD(Test_2_1)
		{
			auto res = P033_DigitCancelingFractions(2, 1).GetResult();
			Assert::AreEqual(110LL, res.first);
			Assert::AreEqual(322LL, res.second);
		}
		TEST_METHOD(Test_3_1)
		{
			auto res = P033_DigitCancelingFractions(3, 1).GetResult();
			Assert::AreEqual(77262LL, res.first);
			Assert::AreEqual(163829LL, res.second);
		}
		TEST_METHOD(Test_3_2)
		{
			auto res = P033_DigitCancelingFractions(3, 2).GetResult();
			Assert::AreEqual(7429LL, res.first);
			Assert::AreEqual(17305LL, res.second);
		}
		TEST_METHOD(Test_4_1)
		{
			auto res = P033_DigitCancelingFractions(4, 1).GetResult();
			Assert::AreEqual(12999936LL, res.first);
			Assert::AreEqual(28131911LL, res.second);
		}
		TEST_METHOD(Test_4_2)
		{
			auto res = P033_DigitCancelingFractions(4, 2).GetResult();
			Assert::AreEqual(3571225LL, res.first);
			Assert::AreEqual(7153900LL, res.second);
		}
		TEST_METHOD(Test_4_3)
		{
			auto res = P033_DigitCancelingFractions(4, 3).GetResult();
			Assert::AreEqual(255983LL, res.first);
			Assert::AreEqual(467405LL, res.second);
		}
	};

	TEST_CLASS(UnitTestEuler034)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(19ULL, P034_DigitFactorials::Solve(20));
		}
	};

	TEST_CLASS(UnitTestEuler035)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(446U, P035_CircularPrimes::Solve(100U));
		}
	};
	
	TEST_CLASS(UnitTestEuler036)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(25U, P036_DoubleBasePalindromes::Solve(10,2));
		}
	};
	
	TEST_CLASS(UnitTestEuler037)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(186U, P037_TruncatablePrimes::Solve(100U));
		}
	};
	
	TEST_CLASS(UnitTestEuler038)
	{
	public:
		TEST_METHOD(Test)
		{
			auto result = P038_PandigitalMultiples::Solve(100U, 8U);
			Assert::AreEqual(18U, result[0]);
			Assert::AreEqual(78U, result[1]);
		}
	};

	TEST_CLASS(UnitTestEuler039)
	{
	public:
		TEST_METHOD(Test)
		{
			P039_IntegerRightTriangles p(100);
			Assert::AreEqual(12U, p.Solve(12U));
			Assert::AreEqual(60U, p.Solve(80U));
		}
	};
	
	TEST_CLASS(UnitTestEuler040)
	{
	public:
		TEST_METHOD(Test)
		{
			P040_ChampernowneConstant p;
			Assert::AreEqual(5040U, p.Solve({1,2,3,4,5,6,7}));
		}
	};

	TEST_CLASS(UnitTestEuler041)
	{
	public:
		TEST_METHOD(Test)
		{
			P041_PandigitalPrime p(10000);
			Assert::AreEqual(-1, p.Solve(100));
			Assert::AreEqual(4231, p.Solve(10000));
		}
	};

	TEST_CLASS(UnitTestEuler042)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(-1LL, P042_CodedTriangleNumbers::Solve(2LL));
			Assert::AreEqual(2LL, P042_CodedTriangleNumbers::Solve(3LL));
			Assert::AreEqual(10LL, P042_CodedTriangleNumbers::Solve(55LL));
		}
	};
	
	TEST_CLASS(UnitTestEuler043)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(22212ULL, P043_SubStringDivisibility::Solve(3U));
		}
	};

	TEST_CLASS(UnitTestEuler044)
	{
	public:
		TEST_METHOD(Test)
		{
			auto res = P044_PentagonNumbers::Solve(10, 2);
			Assert::AreEqual(1ULL, res.size());
			Assert::AreEqual(70ULL, res[0]);
		}

		TEST_METHOD(Test_Large)
		{
			auto res = P044_PentagonNumbers::Solve(1000000, 2);
			Assert::AreEqual(336ULL, res.size());
			Assert::AreEqual(1490525508435ULL, res.back());
		}
	};

	TEST_CLASS(UnitTestEuler045)
	{
	public:
		TEST_METHOD(Test_3_5)
		{
			auto res = P045_TriangularPentagonalHexagonal::Solve(200000000000000ULL, 3U, 5U);
			Assert::AreEqual(
				{1ULL,210ULL,40755ULL,7906276ULL,
				1533776805ULL,297544793910ULL,57722156241751ULL}, 
				res);
		}

		TEST_METHOD(Test_5_6)
		{
			auto res = P045_TriangularPentagonalHexagonal::Solve(200000000000000ULL, 5U, 6U);
			Assert::AreEqual(
				{ 1ULL,40755ULL,1533776805ULL,57722156241751ULL},
				res);
		}
	};

	TEST_CLASS(UnitTestEuler046)
	{
	public:
		TEST_METHOD(Test)
		{
			Assert::AreEqual(1U, P046_GoldbachOtherConjecture::Solve(9U));
			Assert::AreEqual(2U, P046_GoldbachOtherConjecture::Solve(15U));
		}
	};

	TEST_CLASS(UnitTestEuler047)
	{
	public:
		TEST_METHOD(Test)
		{
			auto res1 = P047_DistinctPrimesFactors::Solve(20, 2);
			auto res2 = P047_DistinctPrimesFactors::Solve(644, 3);
			Assert::AreEqual(2ULL, res1.size());
			Assert::AreEqual(14U, res1[0]);
			Assert::AreEqual(20U, res1[1]);
			Assert::AreEqual(1ULL, res2.size());
			Assert::AreEqual(644U, res2[0]);
		}
	};


	TEST_CLASS(UnitTestEuler049)
	{
	public:
		TEST_METHOD(Test_2000_3)
		{
			Assert::AreEqual(std::vector<std::wstring>{L"148748178147"},
				ToStrings(P049_PrimePermutations::Solve(2000, 3)));
		}

		TEST_METHOD(Test_1000000_3)
		{
			auto results = P049_PrimePermutations::Solve(1000000, 3);
			Assert::AreEqual(883ULL, results.size());
			results.resize(14);
			Assert::AreEqual(std::vector<std::wstring>{
					L"148748178147",
					L"296962999629",
					L"114831481318143",
					L"114974171971941",
					L"127131321713721",
					L"127391723921739",
					L"127571725721757",
					L"127991729921799",
					L"148214812181421",
					L"148313148148131",
					L"148974718979481",
					L"185035180385103",
					L"185935189385193",
					L"195433549151439"
				},
				ToStrings(results));
		}

		TEST_METHOD(Test_1000000_4)
		{
			Assert::AreEqual(std::vector<std::wstring>{
					L"83987889379388798837",
					L"121367126317131267136217",
					L"182593185923189253192583",
					L"209359259309309259359209",
					L"302171307121312071317021",
					L"324397329347334297339247",
					L"372877377827382777387727",
					L"403181408131413081418031",
					L"516679566179615679665179",
					L"536801586301635801685301",
					L"536867586367635867685367",
					L"541859545189548519551849",
					L"613763663713713663763613",
					L"617983739861861739983617",
					L"707857757807807757857707"
				},
				ToStrings(P049_PrimePermutations::Solve(1000000, 4)));
		}

		std::vector<std::wstring> ToStrings(const P049_PrimePermutations::Results& results)
		{
			std::vector<std::wstring> vs(results.size());
			for (size_t ii = 0; ii < results.size(); ++ii)
			{
				auto& res = results[ii];
				std::wostringstream ss;
				for (auto v : res)
					ss << v;
				vs[ii] = ss.str();
			}
			return vs;
		}
	};

	TEST_CLASS(UnitTestEuler050)
	{
	public:
		TEST_METHOD(Test_100)
		{
			P050_ConsecutivePrimeSum p(6000000ULL);
			auto res1 = p.Solve(100ULL);
			Assert::AreEqual(41ULL, res1.min_prime_with_max_len);
			Assert::AreEqual(6U, res1.max_consecutive_len);
		}

		TEST_METHOD(Test_10000)
		{
			P050_ConsecutivePrimeSum p(1000ULL);
			auto res2 = p.Solve(1000ULL);
			Assert::AreEqual(953ULL, res2.min_prime_with_max_len);
			Assert::AreEqual(21U, res2.max_consecutive_len);
		}

		TEST_METHOD(Test_1000000000000)
		{
			P050_ConsecutivePrimeSum p(1000000000000ULL);
			auto res1 = p.Solve(1000000000000ULL);
			Assert::AreEqual(999973156643ULL, res1.min_prime_with_max_len);
			Assert::AreEqual(379317U, res1.max_consecutive_len);
		}
	};
}
