#include <iostream>
#include "Sorter.h"

int main()
{
	std::vector<int> v = { 7, 3, 1, 2, 4, 6 };

	(__sorting::SorterIf::get()).sort(v, __sorting::SortingTypes::INSERTION_SORT);

	return 0;
}
