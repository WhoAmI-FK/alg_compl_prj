#pragma once
#include "TimerAPI.h"

namespace __time {
	class TimerImpl : public TimerAPI
	{
	public:
		std::chrono::nanoseconds estimateTime(std::vector<int>& origin, std::vector<int>& arr, __sorting::SortingTypes type) override;
	};
}
