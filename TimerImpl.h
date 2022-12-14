#pragma once
#include "TimerAPI.h"

namespace __time {
	// consider using template
	class TimerImpl : public TimerAPI
	{
	public:
		// function can be overloaded and class be used for general purposes
		// but to avoid extra complexity can be used like this
		std::chrono::nanoseconds getTime(std::vector<int>& a)  override;

		std::chrono::nanoseconds getTime() override;

		void startTimer() override;

		// same
	  //  void setFuncCallback(std::function<void(std::vector<int>&)> f) override;
		std::chrono::nanoseconds estimateTime(std::vector<int>& origin, std::vector<int>& arr, __sorting::SortingTypes type) override;
	private:
		//std::function<void(std::vector<int>&)> m_funCallB;
		std::vector<int> m_arrayCopy;
		std::vector<int> m_sortedArrayCopy;
		decltype(std::chrono::steady_clock::now()) m_lBegin;
		//decltype(std::chrono::steady_clock::now()) m_lEnd;
		// due to the fact we are working with static instance, these vectors exist
		// till the end of the program and don't need to reallocated
	};
}
