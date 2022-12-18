#include <iostream>
#include "SorterIf.h"
#include "Sorter.h"
#include "TimerAPI.h"
#include "DataContainer.h"
#include <random>
#include <cassert>
#include <algorithm>
#include <limits>

#ifdef DEBUG
#define DEBUG_POINT(VAR) std::cout << VAR << std::endl;  
#endif


constexpr int step = 100;
constexpr int maxlen = 10000;
constexpr int times = 100;

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::vector<DataContainer> collectedData;
	for (int len = step; len <= maxlen; len += step) {

		DataContainer sorts;
		sorts.init();
		sorts.len = len;
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

			sorts.INS += __time::TimerAPI::get().estimateTime(original, arr, __sorting::SortingTypes::INSERTION_SORT);

			sorts.MER += __time::TimerAPI::get().estimateTime(original, arr, __sorting::SortingTypes::MERGE_SORT);

			sorts.QUI += __time::TimerAPI::get().estimateTime(original, arr, __sorting::SortingTypes::QUICK_SORT);
		
			sorts.HEP += __time::TimerAPI::get().estimateTime(original, arr, __sorting::SortingTypes::HEAP_SORT);

//			sorts.INS_B += __time::TimerAPI::get().estimateTime(arr, sorted, __sorting::SortingTypes::INSERTION_SORT);

//			sorts.MER_B += __time::TimerAPI::get().estimateTime(arr, sorted, __sorting::SortingTypes::MERGE_SORT);

//			sorts.QUI_B += __time::TimerAPI::get().estimateTime(arr, sorted, __sorting::SortingTypes::QUICK_SORT);

//			sorts.HEP_B += __time::TimerAPI::get().estimateTime(arr, sorted, __sorting::SortingTypes::HEAP_SORT);
		}
		
		std::cout
			<< len << " "
			<< sorts.INS.count() / times << " "
			<< sorts.MER.count() / times << " "
			<< sorts.QUI.count() / times << " "
			<< sorts.HEP.count() / times << " "
//			<< sorts.INS_B.count() / times << " "
//			<< sorts.MER_B.count() / times << " "
//			<< sorts.QUI_B.count() / times << " "
//			<< sorts.HEP_B.count() / times << " "
			<< std::endl;

		collectedData.push_back(sorts);
	}

	DataContainer::outputDataToFile(collectedData, times, SortType::NORMAL);
//	DataContainer::outputDataToFile(collectedData, times, SortType::SORTED);
	return 0;
}
