#include "TimerImpl.h"
#include <iterator>
#include "SorterIf.h"

namespace __time {

	TimerAPI& TimerAPI::get()
	{
		static TimerImpl timer;
		return timer;
	}

	std::chrono::nanoseconds TimerImpl::getTime(std::vector<int>& a)
	{
		std::copy(a.begin(), a.end(), std::back_inserter(m_arrayCopy));
		
		auto begin = std::chrono::steady_clock::now();
	//	m_funCallB(m_arrayCopy);
		auto end = std::chrono::steady_clock::now();

		assert(std::is_sorted(m_arrayCopy.begin(), m_arrayCopy.end()));
		
		std::chrono::nanoseconds total(end - begin);
		return total;
	}

	void TimerImpl::startTimer()
	{
		m_lBegin = std::chrono::steady_clock::now();
	}
	
	std::chrono::nanoseconds TimerImpl::getTime()
	{
		std::chrono::nanoseconds total(std::chrono::steady_clock::now() - m_lBegin);
		return total;
	}

/*	void TimerImpl::setFuncCallback(std::function<void(std::vector<int>&)> f)
	{
		m_funCallB = f;
	}
*/
	std::chrono::nanoseconds TimerImpl::estimateTime(std::vector<int>& origin, std::vector<int>& arr, __sorting::SortingTypes type)
	{
		std::copy(origin.begin(), origin.end(), std::back_inserter(arr));
		auto begin = std::chrono::steady_clock::now();
		__sorting::SorterIf::get().sort(arr, type);
		auto end = std::chrono::steady_clock::now();
		
		assert(std::is_sorted(arr.begin(), arr.end()));
		std::chrono::nanoseconds total(end - begin);
		return total;
	}
}