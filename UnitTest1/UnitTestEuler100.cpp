#include "pch.h"
#include "CppUnitTest.h"
#include "../HackerRankEulerProblems/80/P068_MagicNGonRing.h"
#include "../HackerRankEulerProblems/80/P076_CountingSummations.h"
#include "../HackerRankEulerProblems/80/P078_CoinPartitions.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestEuler
{
	TEST_CLASS(UnitTestEuler068)
	{
	public:
		TEST_METHOD(Test_3_9)
		{
			P068MagicNGonRing problem;
			problem.Solve(3, 9);
			Assert::AreEqual(problem.results.size(), (size_t)2);
			Assert::AreEqual(*problem.results.begin(), std::string("423531612"));
			Assert::IsTrue(problem.results.count("432621513") == 1);
		}

		TEST_METHOD(Test_3_10)
		{
			P068MagicNGonRing problem;
			problem.Solve(3, 10);
			Assert::AreEqual(problem.results.size(), (size_t)2);
			Assert::AreEqual(*problem.results.begin(), std::string("235451613"));
			Assert::IsTrue(problem.results.count("253631415") == 1);
		}

		TEST_METHOD(Test_3_11)
		{
			P068MagicNGonRing problem;
			problem.Solve(3, 11);
			Assert::AreEqual(problem.results.size(), (size_t)2);
			Assert::AreEqual(*problem.results.begin(), std::string("146362524"));
			Assert::IsTrue(problem.results.count("164542326") == 1);
		}

		TEST_METHOD(Test_3_12)
		{
			P068MagicNGonRing problem;
			problem.Solve(3, 12);
			Assert::AreEqual(problem.results.size(), (size_t)2);
			Assert::AreEqual(*problem.results.begin(), std::string("156264345"));
			Assert::IsTrue(problem.results.count("165354246") == 1);
		}

		TEST_METHOD(Test_10_32_worst_case)
		{
			P068MagicNGonRing problem;
			problem.Solve(10, 32);
			Logger::WriteMessage((std::string("ring count: ") + std::to_string(problem.results.size())).c_str());
		}
	};

	TEST_CLASS(UnitTestEuler076)
	{
	public:
		TEST_METHOD(Test_5)
		{
			Assert::AreEqual(6U, P076_CountingSummations::Solve(5U));
		}

		TEST_METHOD(Test_6)
		{
			Assert::AreEqual(10U, P076_CountingSummations::Solve(6U));
		}

		TEST_METHOD(Test_7)
		{
			Assert::AreEqual(14U, P076_CountingSummations::Solve(7U));
		}

		TEST_METHOD(Test_1000)
		{
			Assert::AreEqual(709496665U, P076_CountingSummations::Solve(1000U));
		}
	};

	TEST_CLASS(UnitTestEuler078)
	{
	public:
		TEST_METHOD(Test_5)
		{
			Assert::AreEqual(7U, P078_CoinPartitions::Solve(5U));
		}

		TEST_METHOD(Test_6)
		{
			Assert::AreEqual(11U, P078_CoinPartitions::Solve(6U));
		}

		TEST_METHOD(Test_60000)
		{
			Assert::AreEqual(168497963U, P078_CoinPartitions::Solve(60000U));
		}
	};
}
