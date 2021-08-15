#ifndef LIBS_TIMER_H_
#define LIBS_TIMER_H_

#include <windows.h>
#include <profileapi.h>
#include <iostream>

#undef min
#undef max

namespace hackerrank_euler
{

struct Timer
{
	LARGE_INTEGER	startTime;
	LARGE_INTEGER	elapsedMS;
	bool			output;

	Timer(bool _output = true)
	{
		output = _output;
		QueryPerformanceCounter(&startTime);
		elapsedMS.QuadPart = MAXLONGLONG;
	}
	~Timer()
	{
		if (elapsedMS.QuadPart == MAXLONGLONG)
			Stop();
		if (output)
			std::cout << "Time: " << elapsedMS.QuadPart << "ms" << std::endl;
	}
	LONGLONG Stop()
	{
		LARGE_INTEGER	EndingTime;
		QueryPerformanceCounter(&EndingTime);
		LARGE_INTEGER	Frequency;
		QueryPerformanceFrequency(&Frequency);
		elapsedMS.QuadPart = EndingTime.QuadPart - startTime.QuadPart;
		elapsedMS.QuadPart *= 1000;
		elapsedMS.QuadPart /= Frequency.QuadPart;
		return elapsedMS.QuadPart;
	}
};

}
#endif // LIBS_TIMER_H_
