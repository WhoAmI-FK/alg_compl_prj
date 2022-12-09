#include <iostream>
#include "Sorter.h"

int main()
{
/*	std::vector<int> v = {7, 3, 1, 2, 4, 6};

	(__sorting::SorterIf::get()).sort(v, __sorting::SortingTypes::INSERTION_SORT);
*/

	std::vector<int> v2 = { 7,1000, 3, 1, 2, 1000, 1000, 1000, 4, -5, -999, 23, 11, 0, 6 };

	(__sorting::SorterIf::get()).sort(v2, __sorting::SortingTypes::MERGE_SORT);

	return 0;
}
