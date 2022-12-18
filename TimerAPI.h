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
		virtual std::chrono::nanoseconds estimateTime(std::vector<int>& origin, std::vector<int>& arr, __sorting::SortingTypes type) = 0;
	};
}