#pragma once

#include <time.h>
#include <conio.h>

template <typename T>
class Countdown
{
	clock_t myClock;
	T myCount;				// Countdown starts from this number.
public:
	Countdown(): myCount(0), myClock(clock()) 
	{}
	Countdown(const T&): myCount(T), myClock(clock()) 
	{}
	~Countdown() 
	{}
	T GetCurrentCount()
	{
		T CurrentCount = myCount - (clock()-myClock)/CLOCKS_PER_SEC;
		return CurrentCount > 0 ? CurrentCount : 0;
	}
	void SetCount(const T& newCount)
	{
		myCount = newCount;
	}
	void Start()
	{
		myClock = clock();
	}
	void IncreaseCount(const T& toAdd)
	{
		myCount += toAdd;
	}
	bool isFinished()
	{
		return GetCurrentCount() == 0 ? true : false;
	}
};