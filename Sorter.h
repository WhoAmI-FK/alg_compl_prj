#pragma once
#include "SorterIf.h"
#define DEBUG

namespace __sorting {

	class Sorter : public SorterIf
	{
	public:
		void sort(std::vector<int>& a, SortingTypes selectedType) override; 

		void insertionSort(std::vector<int>& a);
	};

};