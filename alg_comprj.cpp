#include <iostream>
#include "Sorter.h"

int main()
{
/*	std::vector<int> v = {7, 3, 1, 2, 4, 6};

	(__sorting::SorterIf::get()).sort(v, __sorting::SortingTypes::INSERTION_SORT);
*/

	std::vector<int> v2 = { 7, 3, 1,1000,-1000,11,111111,1000,0,0,0,0,1,1,1,1, 2, 4, 6};
	(__sorting::SorterIf::get()).sort(v2, __sorting::SortingTypes::QUICK_SORT);

	return 0;
}
