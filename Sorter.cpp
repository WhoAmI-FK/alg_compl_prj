#include "Sorter.h"

#include <cstdint>

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
			quickSort(a);
			break;
		case SortingTypes::MERGE_SORT:
			mergeSort(a);
			break;
		case SortingTypes::HEAP_SORT:
			heapSort(a);
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

	void Sorter::mergeSort(std::vector<int>& a, std::size_t left, std::size_t right)
	{
		if (left >= right)
		{
			return;
		}

		std::size_t middle = (left + right) / 2;
		mergeSort(a, left, middle);
		mergeSort(a, middle + 1, right);

		if(a[middle]>a[middle+1])
		helperMergeArray(a, left, right);

	/*	for (const auto& v : a)
		{
			std::cout << v << " ";
		}
		std::cout << std::endl;
	*/
	}
	
	void Sorter::helperMergeArray(std::vector<int>& a, std::size_t leftStart, std::size_t rightEnd)
	{
		std::size_t leftEnd = (leftStart + rightEnd) / 2;
		std::size_t rightStart = leftEnd + 1;
		std::size_t left = leftStart;
		std::vector<int> output;
		output.resize(rightEnd - leftStart+1);
		std::size_t index = 0;
		while(left <= leftEnd && rightStart <=rightEnd )
		{
			if (a[left] <= a[rightStart])
			{
				output[index]=a[left];
				left++;
			}
			else {
				output[index] = a[rightStart];
				rightStart++;
			}
			index++;
		}

		for (std::size_t i = left; i <= leftEnd; i++) {
			output[index++] = a[i];
		}

		for (std::size_t i = rightStart; i <= rightEnd; i++) {
			output[index++] = a[i];
		}

		for (std::size_t i = leftStart, j =0; i <= rightEnd; i++,j++)
		{
			a[i] = output[j];
		}
	}

	void Sorter::mergeSort(std::vector<int>& a)
	{
		if (a.size() <= 1)
		{
			return;
		}
		mergeSort(a, 0, a.size()-1);
		for (const auto& v : a)
		{
			std::cout << v << " ";
		}
	}

	void Sorter::quickSort(std::vector<int>& a, int left, int right)
	{
		if (left < right && left>=0 && right>=0)
		{
			std::size_t pivot = hoaresPartition(a, left, right);
			quickSort(a, left, pivot - 1);
			quickSort(a, pivot + 1, right);
		}

	}

	std::size_t Sorter::hoaresPartition(std::vector<int>&a, int left, int right)
	{
		std::size_t pivot = left++;

		while (left <= right && right > pivot)
		{

			if(a[left] <= a[pivot])
			{
				left++;
			}
			else if (a[right] > a[pivot])
			{
				right--;
			}
			else {
				std::swap(a[right], a[left]);
			}
		}
		std::swap(a[pivot], a[right]);
		return right;

		
	}

	void Sorter::quickSort(std::vector<int>& a)
	{
		if (a.size() <= 1)
		{
			return;
		}

		quickSort(a, 0, a.size()-1);
		for (const auto& v : a)
		{
			std::cout << v << " ";
		}
	}



	void Sorter::heapSort(std::vector<int>& a)
	{

		class HeapF {
		public:
			HeapF()
			{
				top = 0;

			}


			int getParent(int pos, int maxIndex)
			{
				pos = (pos - 1) / 2;
				if (pos < 0)
				{
					//
				}

				return pos;
			}

			void heapify(std::vector<int>& a)
			{

			}

		private:
			void helperPrint(std::vector<int>& a)
			{
				std::cout << "\n------------------------\n";
				for (auto& v : a)
				{
					std::cout << v << " ";
				}
				std::cout << "\n------------------------\n\n";

			}

			std::int64_t top;
		};
		HeapF instance;
//		instance.buildHeap(a);
	}
}