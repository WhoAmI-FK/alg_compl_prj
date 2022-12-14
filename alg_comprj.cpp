#include <iostream>
#include "SorterIf.h"
#include "Sorter.h"
#include "TimerAPI.h"
#include <random>
#include <cassert>
#include <algorithm>

constexpr int step = 10;
constexpr int maxlen = 100;
constexpr int times = 10;

int main()
{
/*	std::vector<int> v = {7, 3, 1, 2, 4, 6};

	(__sorting::SorterIf::get()).sort(v, __sorting::SortingTypes::INSERTION_SORT);
*/

//	std::vector<int> v2 = { 7, 3, 1,1000,-1000,11,111111,1000,0,0,0,0,1,1,1,1, 2, 4, 6};
//	(__sorting::SorterIf::get()).sort(v2, __sorting::SortingTypes::QUICK_SORT);
	
	std::random_device rd;
	std::mt19937 gen(rd());
	__sorting::Sorter s;
	for (int len = step; len < maxlen; len += step) {
		std::chrono::nanoseconds INS(0);
		std::chrono::nanoseconds QUI(0);
		std::chrono::nanoseconds MER(0);
		std::chrono::nanoseconds HEP(0);

		std::vector<int> original(len);
		for (int i = 0; i < len; i++)
		{
			original[i] = i;
		}

		std::vector<int> arr;
		std::vector<int> sorted;

		for (int t = 0; t < times; t++)
		{
			std::shuffle(original.begin(), original.end(), gen);

			INS += __time::TimerAPI::get().estimateTime(original, arr, __sorting::SortingTypes::INSERTION_SORT);

			MER += __time::TimerAPI::get().estimateTime(original, arr, __sorting::SortingTypes::MERGE_SORT);

			QUI += __time::TimerAPI::get().estimateTime(original, arr, __sorting::SortingTypes::QUICK_SORT);

			HEP += __time::TimerAPI::get().estimateTime(original, arr, __sorting::SortingTypes::HEAP_SORT);
		}
		
		std::cout
			<< len << " "
			<< INS.count() / times << " "
			<< MER.count() / times << " "
			<< QUI.count() / times << " "
			<< HEP.count() / times << " "
			<< std::endl;

	}
	return 0;
}
