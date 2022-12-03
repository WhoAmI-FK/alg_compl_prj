#pragma once
#include <vector>
namespace __sorting {

	enum class SortingTypes {
		INSERTION_SORT = 0,
		QUICK_SORT,
		MERGE_SORT,
		HEAP_SORT
	};


	class SorterIf
	{
	public:
		static SorterIf& get();
		virtual void sort(std::vector<int>& a, SortingTypes selectedType) = 0;
	};
}