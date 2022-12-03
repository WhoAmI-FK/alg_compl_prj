#include "Sorter.h"

#ifdef DEBUG
#include <iostream>
#endif

namespace __sorting {



	SorterIf& SorterIf::get()
	{
		static Sorter sorter;
		return sorter;
	}

	void Sorter::sort(std::vector<int>& a, SortingTypes selectedType)
	{
		switch (selectedType)
		{
		case SortingTypes::INSERTION_SORT:
			insertionSort(a);
			break;
		case SortingTypes::QUICK_SORT:
			break;
		case SortingTypes::MERGE_SORT:
			break;
		case SortingTypes::HEAP_SORT:
			break;
		default:
			// exception handling
			break;
		}
	}

	void print(std::vector<int>& a)
	{
		std::cout << "\n-----------------------------------------\n";
		for (const auto& v : a)
		{
			std::cout << v << " ";
		}
		std::cout << "\n-----------------------------------------\n";
	}

	void Sorter::insertionSort(std::vector<int>& a)
	{
		if (a.size() <= 1)
		{
			return;
		}

		for (auto t = a.begin() + 1; t != a.end(); t++)
		{
			int compVal = *t;
			auto temp = t;
			while ((temp != a.begin()) && *(temp - 1) > compVal)
			{

#ifdef DEBUG
				print(a);
#endif // DEBUG

				std::swap(*temp , *(temp - 1));
				temp--;
#ifdef DEBUG
				print(a);
#endif // DEBUG

			}
			*(temp) = compVal;
		}
	}
}