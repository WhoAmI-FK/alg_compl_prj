#pragma once
#include <chrono>
#include <algorithm>
#include <cassert>
#include <vector>
#include <functional>
#include "SorterIf.h"

namespace __time {

	class TimerAPI
	{
	public:
		static TimerAPI& get();

		// function can be overloaded and class be used for general purposes
		// but to avoid extra complexity can be used like this
		virtual std::chrono::nanoseconds getTime(std::vector<int>& a) = 0;
		virtual std::chrono::nanoseconds getTime() = 0;
		virtual void startTimer() = 0;
		virtual std::chrono::nanoseconds estimateTime(std::vector<int>& origin, std::vector<int>& arr, __sorting::SortingTypes type) = 0;

		// same
	//	virtual void setFuncCallback(std::function<void(std::vector<int>&)> f) = 0;

	};
}