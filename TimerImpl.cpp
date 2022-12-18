#include "TimerImpl.h"
#include <iterator>
#include "SorterIf.h"
#include "Sorter.h"

namespace __time {

	TimerAPI& TimerAPI::get()
	{
		static TimerImpl timer;
		return timer;
	}

	std::chrono::nanoseconds TimerImpl::estimateTime(std::vector<int>& origin, std::vector<int>& arr, __sorting::SortingTypes type)
	{
		arr.resize(origin.size());
		arr.reserve(origin.size() + 10);
		std::copy(origin.begin(), origin.end(), arr.begin());

		auto begin = std::chrono::steady_clock::now();
		__sorting::SorterIf::get().sort(arr, type);
		auto end = std::chrono::steady_clock::now();
		
		assert(std::is_sorted(arr.begin(), arr.end()));
		std::chrono::nanoseconds total(end - begin);
		return total;
	}
}