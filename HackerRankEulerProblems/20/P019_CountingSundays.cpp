#include "P019_CountingSundays.h"
#include <iostream>

// (0 = Saturday, 1 = Sunday, 2 = Monday, ..., 6 = Friday)
static int get_day_of_week(int64_t Y, int32_t m, int32_t d)
{
	if (m == 1 || m == 2)
	{
		m += 12;
		--Y;
	}
	auto n1 = (13 * (m + 1)) / 5;
	auto n2 = Y / 4;
	auto n3 = Y / 100;
	auto n4 = Y / 400;
	int h = (d + n1 + Y + n2 - n3 + n4) % 7;
	//int d = ((h + 5) % 7) + 1;
	return h;
}

static int compare_dates(const P019_CountingSundays::Date& d1, const P019_CountingSundays::Date& d2)
{
	if (d1.Y == d2.Y)
	{
		if (d1.m == d2.m)
			return d1.d - d2.d;
		return d1.m - d2.m;
	}
	return d1.Y < d2.Y ? -1 : 1;
}

int P019_CountingSundays::Solve(Date dt1, Date dt2)
{
	int sum = 0;
	if (compare_dates(dt1, dt2) > 0)
	{
		std::swap(dt1, dt2);
	}

	if (dt1.d > 1)
	{
		if (dt1.m == 12)
		{
			dt1.m = 1;
			++dt1.Y;
		}
		else
			++dt1.m;
		dt1.d = 1;
	}

	if (compare_dates(dt1, dt2) <= 0)
	{
		int month_from = dt1.m;
		int month_to = 12;
		for (int64_t Y = dt1.Y; Y <= dt2.Y; ++Y)
		{
			if (Y == dt2.Y)
				month_to = dt2.m;
			for (int mm = month_from; mm <= month_to; ++mm)
			{
				if (get_day_of_week(Y, mm, 1) == 1)
					++sum;
			}
			month_from = 1;
		}
	}
	return sum;
}

void P019_CountingSundays::main()
{
	std::ios_base::sync_with_stdio(false);
	int32_t T;
	std::cin >> T;
	for (int32_t tt = 0; tt < T; ++tt)
	{
		Date dt1, dt2;
		std::cin >> dt1.Y >> dt1.m >> dt1.d;
		std::cin >> dt2.Y >> dt2.m >> dt2.d;
		std::cout << Solve(dt1, dt2) << std::endl;
	}
}
