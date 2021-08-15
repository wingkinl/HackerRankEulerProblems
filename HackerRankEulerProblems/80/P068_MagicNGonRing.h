#ifndef HACKERRANK_EULER_068_H_
#define HACKERRANK_EULER_068_H_

#include <set>
#include <string>
#include <array>
#include <vector>

// https://www.hackerrank.com/contests/projecteuler/challenges/euler068/problem

//#define _GET_MAX_POSSIBLE_LINES

struct P068MagicNGonRing
{
	std::set<std::string>	results;

	void Solve(int lines, int total);

	static void main();

#ifdef _GET_MAX_POSSIBLE_LINES
	static size_t max_possible_lines;
#endif // _GET_MAX_POSSIBLE_LINES
private:
	// use 4 instead of 3 for better optimization due to alignment
	using Line3 = std::array<int8_t, 4>;

	enum {
		kMaxLineSize				= 10,
		kMaxNumber					= kMaxLineSize * 2,
		kMaxPossibleLineCandidates	= 45,
	};

	struct NGonRingCandidate 
	{
		int		inner_nums[kMaxLineSize] = {1,2,3,4,5,6,7,8,9,10};
		// true means inner node
		bool	inner_flags[kMaxNumber+1] = { 0 };
		std::vector<Line3> all_lines;
		int		lines;
		int		total;
	public:
		NGonRingCandidate(int lines, int total);

		void GenerateAllPossibleLines();

		bool CheckInnerRing();

		bool MakeNextInnerRing();
	private:
		const int kInner_ring_sum;
		const int kMax_first_inner_num;
	};

	friend class NGonRingBuilder;

	//using Rings = std::array<Line3, 10>;
	//using Rings = std::vector<Line3>;
	using Rings = Line3[10];

	class NGonRingBuilder
	{
	public:
		NGonRingBuilder(P068MagicNGonRing* problem);

		void Build(NGonRingCandidate& ngon);
	private:
		bool GetValidLines(NGonRingCandidate& ngon);

		void BuildNextLineForRing(int line_num);
	private:
		int		first_inner_num_;
		P068MagicNGonRing* problem_;
		int		lines_;
		Rings	rings_;
		Line3	valid_lines_[kMaxPossibleLineCandidates];
		int		line_count_ = 0;
		char	used_num_[kMaxNumber+1] = { 0 };
	};
};

#endif // HACKERRANK_EULER_068_H_
