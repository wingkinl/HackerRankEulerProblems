#include "P068_MagicNGonRing.h"
#include <algorithm>
#include <iostream>
#include <libs/timer.h>

// For a specific N-Gon ring of given number of lines (N) and the total (S):
// 1) the sum of all numbers is
//
//	1 + 2 + 3 + ... + 2*N = 2*N * (1 + 2*N) / 2 = N * ( 2*N + 1)
//
// 2) the sum of each line is S, and there are N lines, the sum is N * S
//    and because the inner ring numbers are added twice, we get:
//
//	2* (inner_sum) + outer_sum = N * S
//
// subtract 2) with 1), we know the sum of the inner ring is:
//
// inner_sum = N * S - N * ( 2*N + 1) = N * (S - 2*N - 1)

// When generating all possible inner numbers, we start from 1,2,3,4,... until N-1 position
// that means we compute the last number based on the subtraction of S and sum of the first
// N-1 numbers. We keep increasing the last number until it reaches the maximal possible digit
// at that position, and carry up one digit. This way we can get all cases without duplicates.
// so, the first one has maximal limitation:
// 1) clearly it must be equal to or smaller than N + 1
// 
// 2) the sum of the inner ring is known (inner_sum), when the first inner number is the maximum (m):
//
//   m + m+1 + m+2 + m+3 + ... (m+N-1) = S
//
// ==> m = (S - N*(N-1)) / 2 / N

P068MagicNGonRing::NGonRingCandidate::NGonRingCandidate(int lines, int total)
	: kInner_ring_sum(lines * (total - 2 * lines - 1))
	, kMax_first_inner_num(std::min((kInner_ring_sum - lines * (lines - 1) / 2) / lines, lines + 1))
{
	this->lines = lines;
	this->total = total;
}

#ifdef _GET_MAX_POSSIBLE_LINES
size_t P068MagicNGonRing::max_possible_lines = 0;
#endif // _GET_MAX_POSSIBLE_LINES

void P068MagicNGonRing::NGonRingCandidate::GenerateAllPossibleLines()
{
	const auto max_number = lines * 2;
	all_lines.reserve(kMaxPossibleLineCandidates);
	Line3 temp;
	for (int ii = 1; ii <= lines + 1; ++ii)
	{
		for (int jj = ii + 1; jj <= max_number; ++jj)
		{
			int num3 = total - ii - jj;
			if (num3 > jj && num3 <= max_number)
			{
				temp[0] = ii;
				temp[1] = jj;
				temp[2] = num3;
				all_lines.push_back(temp);
			}
		}
	}
#ifdef _GET_MAX_POSSIBLE_LINES
	if (all_lines.size() > P068MagicNGonRing::max_possible_lines)
		P068MagicNGonRing::max_possible_lines = all_lines.size();
#endif // _GET_MAX_POSSIBLE_LINES
}

bool P068MagicNGonRing::NGonRingCandidate::CheckInnerRing()
{
	const auto max_number = lines * 2;
	//memset(_inner_flags, 0, sizeof(bool)*(max_number+1));
	std::fill(inner_flags, inner_flags + max_number + 1, false);

	int sum_other = 0;
	for (int ii = 0; ii < lines - 1; ++ii)
	{
		sum_other += inner_nums[ii];
		inner_flags[inner_nums[ii]] = true;
	}
	auto last_inner_num = kInner_ring_sum - sum_other;
	if (last_inner_num <= max_number && last_inner_num > inner_nums[lines-2])
	{
		inner_nums[lines - 1] = last_inner_num;
		inner_flags[last_inner_num] = true;
		// there are still some cases that are invalid. e.g.:
		// for each inner number, there must be at least one other inner number 
		// to consist a 3 tuple for a line, and the outer number must be in 
		// range and not also an inner number.
		// this might not be that helpful in terms of performance though
		bool valid = true;
		for (int ii = 0; ii < lines; ++ii)
		{
			bool found = false;
			for (int jj = 0; jj < lines; ++jj)
			{
				if (jj != ii)
				{
					auto outer_num = total - (inner_nums[ii] + inner_nums[jj]);
					if (outer_num >= 0 && outer_num <= max_number && !inner_flags[outer_num])
					{
						found = true;
						break;
					}
				}
			}
			if (!found)
			{
				valid = false;
				break;
			}
		}
		return valid;
	}
	return false;
}

bool P068MagicNGonRing::NGonRingCandidate::MakeNextInnerRing()
{
	// we start building the inner ring from 1,2,3,4,...N-2, L (L stands for the last one)
	// compute the L based on the first N-2 numbers. see CheckInnerRing()
	// then we increase the last one unless we have to carry the digit to its left
	int pos = lines - 2;
	// the maximal possible number for each node is N+nPos+1
	while (pos > 0 && inner_nums[pos] == lines+pos+1) --pos;
	++inner_nums[pos];
	if (pos == 0 && inner_nums[0] > kMax_first_inner_num)
		return false;
	for (int jj = pos + 1; jj < lines - 1; ++jj)
	{
		inner_nums[jj] = inner_nums[jj - 1] + 1;
	}
	return true;
}

P068MagicNGonRing::NGonRingBuilder::NGonRingBuilder(P068MagicNGonRing* problem)
{
	problem_ = problem;
}

void P068MagicNGonRing::NGonRingBuilder::Build(NGonRingCandidate& ngon)
{
	if (!GetValidLines(ngon))
		return;
	lines_ = ngon.lines;
	const auto max_number = ngon.lines * 2;
	auto first_outer_num_it = std::find(ngon.inner_flags+1, ngon.inner_flags + max_number + 1, false);
	auto min_outer_num = std::distance(ngon.inner_flags, first_outer_num_it);

	//_rings.resize(ngon._lines);
	for (int line_idx = 0; line_idx < line_count_; ++line_idx)
	{
		auto& line = valid_lines_[line_idx];
		if (line[0] == min_outer_num)
		{
			rings_[0] = line;
			BuildNextLineForRing(1);
			std::swap(rings_[0][1], rings_[0][2]);
			BuildNextLineForRing(1);
		}
	}
}

bool P068MagicNGonRing::NGonRingBuilder::GetValidLines(NGonRingCandidate& ngon)
{
	auto& inner_flag = ngon.inner_flags;
	for (auto& line : ngon.all_lines)
	{
		auto inner_count = inner_flag[line[0]] + inner_flag[line[1]] + inner_flag[line[2]];
		if (inner_count == 2)
		{
			valid_lines_[line_count_] = line;
			auto& cur_valid_line = valid_lines_[line_count_];
			// make the outer number becomes the first for faster look up
			auto it = std::find_if(cur_valid_line.begin(), cur_valid_line.end(), 
				[&inner_flag](auto v) {return !inner_flag[v]; });
			std::swap(*it, cur_valid_line.front());
			++line_count_;
		}
	}
	return line_count_ >= ngon.lines;
}

void P068MagicNGonRing::NGonRingBuilder::BuildNextLineForRing(int line_num)
{
	auto& curLine = rings_[line_num - 1];
	++used_num_[curLine[0]];
	++used_num_[curLine[1]];
	++used_num_[curLine[2]];
	auto& next_line = rings_[line_num];
	const char last_inner_num = line_num + 1 == lines_ ? 1 : 0;
	for (int ii = 0; ii < line_count_; ++ii)
	{
		auto& line = valid_lines_[ii];
		// the outer node must be used for the first time
		if (used_num_[line[0]])
			continue;
		bool found = false;
		// the end node must be used for the first time unless it's the last line
		if (line[1] == curLine[2])
		{
			if (used_num_[line[2]] == last_inner_num)
			{
				next_line = line;
				found = true;
			}
		}
		else if (line[2] == curLine[2] && used_num_[line[1]] == last_inner_num)
		{
			next_line[0] = line[0];
			next_line[1] = line[2];
			next_line[2] = line[1];
			found = true;
		}
		if (!found)
			continue;
		if (line_num + 1 == lines_)
		{
	#ifndef _GET_MAX_POSSIBLE_LINES
			if (next_line[2] == rings_[0][1])
			{
				char buf[100];
				char* pos = buf;

				for (int ii = 0; ii < lines_; ++ii)
				{
					auto& line_in_ring = rings_[ii];
					pos += sprintf(pos, "%d", line_in_ring[0]);
					pos += sprintf(pos, "%d", line_in_ring[1]);
					pos += sprintf(pos, "%d", line_in_ring[2]);
				}
				problem_->results.emplace(buf);
			}
	#endif // _GET_MAX_POSSIBLE_LINES
		}
		else
		{
			BuildNextLineForRing(line_num + 1);
		}
	}
	--used_num_[curLine[0]];
	--used_num_[curLine[1]];
	--used_num_[curLine[2]];
}

void P068MagicNGonRing::Solve(int lines, int total)
{
	results.clear();

	NGonRingCandidate ring(lines, total);
	ring.GenerateAllPossibleLines();
	
	while (true)
	{
		if (ring.CheckInnerRing())
		{
			NGonRingBuilder ring_builder(this);
			ring_builder.Build(ring);
		}

		if (!ring.MakeNextInnerRing())
			break;
	}
}

//#define _FIND_WORST_CASE
#define _OUTPUT_RESULTS

#ifdef _FIND_WORST_CASE
static void FindWorstCaseInEuler68()
{
	struct TestCase
	{
		int lines = 0;
		int total = 0;
		size_t solution = 0;
		LONGLONG time = 0;
	};
	size_t most_time_consuming_input = 0;
	LONGLONG max_time = 0;
	std::vector<TestCase> cases;
	cases.reserve(50);
	P068MagicNGonRing problem;
	for (int lines = 3; lines <= 10; ++lines)
	{
		const int min_total = 3 + 2 * lines;
		const int max_total = 4 * lines;
		for (int total = min_total; total <= max_total; ++total)
		{
			hackerrank_euler::Timer timer(false);
			problem.Solve(lines, total);
			std::cout << lines << " " << total << " = " << problem.results.size() << "\n";
			LONGLONG elapsed = timer.Stop();
			cases.push_back({ lines, total, problem.results.size(), elapsed });
			if (elapsed > max_time)
			{
				max_time = elapsed;
				most_time_consuming_input = cases.size() - 1;
			}
		}
		std::cout << "\n";
	}
	auto& worst_case = cases[most_time_consuming_input];
	std::cout << "most time consuming: " << worst_case.lines
		<< " " << worst_case.total
		<< " solution: " << worst_case.solution
		<< " time: " << max_time << "\n";
}
#endif

void P068MagicNGonRing::main()
{
	std::ios_base::sync_with_stdio(false);

#ifdef _FIND_WORST_CASE
	FindWorstCaseInEuler68();
#else
	int lines = 3;
	int total = 9;
	std::cin >> lines >> total;
	hackerrank_euler::Timer timer;
	P068MagicNGonRing problem;
	problem.Solve(lines, total);
	timer.Stop();
#ifdef _OUTPUT_RESULTS
	for (auto& result : problem.results)
		std::cout << result << "\n";
#endif // _OUTPUT_RESULTS
#endif // _FIND_WORST_CASE
}
