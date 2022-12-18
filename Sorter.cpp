#include "Sorter.h"
#include <cstdint>
#include <iostream>
#include <stdexcept>

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
		}
	}

	void Sorter::print(std::vector<int>& a)
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

		for (std::size_t i = 1; i < a.size(); i++)
		{
			int val = a[i];
			int cur = i;
			while ((cur > 0) && a[cur-1] > val)
			{
				a[cur] = a[cur-1];
				cur--;
			}
			a[cur] = val;
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

		if (a[middle] > a[middle + 1])
			helperMergeArray(a, left, right);

	}

	void Sorter::helperMergeArray(std::vector<int>& a, std::size_t leftStart, std::size_t rightEnd)
	{
		std::size_t leftEnd = (leftStart + rightEnd) / 2;
		std::size_t rightStart = leftEnd + 1;
		std::size_t left = leftStart;
		std::vector<int> output;
		output.resize(rightEnd - leftStart + 1);
		std::size_t index = 0;
		while (left <= leftEnd && rightStart <= rightEnd)
		{
			if (a[left] <= a[rightStart])
			{
				output[index] = a[left];
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

		for (std::size_t i = leftStart, j = 0; i <= rightEnd; i++, j++)
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
		mergeSort(a, 0, a.size() - 1);
	}

	
	void Sorter::quickSort(std::vector<int>& a, int left, int right)
	{
		if (left < right) {
			int pivot = hoaresPartition(a, left, right);
			quickSort(a, left, pivot - 1);
			quickSort(a, pivot + 1, right);
		}
	}

	int Sorter::hoaresPartition(std::vector<int>& a, int left, int right)
	{
			int border = right;
			int& pivot = a[left];
			while (left < right)
			{
				left++;
				while (left <= right && a[left] < pivot)
				{
					left++;
				}

				while (right >= left && a[right] > pivot)
				{
					right--;
				}
				if (left <= border && left < right)
				{
					std::swap(a[left], a[right]);
				}
			}

			std::swap(pivot, a[right]);
			return right;
	}
	

	void Sorter::quickSort(std::vector<int>& a)
	{
		if (a.size() <= 1)
		{
			return;
		}

		quickSort(a, 0, a.size() - 1);
	}


	void Sorter::heapSort(std::vector<int>& a)
	{
		class Heap {
		private:
			static void heapify(std::vector<int>& a)
			{
				int lastParent = getParent(a.size() - 1);


				while (lastParent >= 0)
				{
					fixHeap(a, lastParent, a.size() - 1);
					lastParent--;
				}
			}

			static void removeTop(std::vector<int>& a, int& end)
			{
				std::swap(a[0], a[end]);
				end--;
			}

			static inline void fixHeap(std::vector<int>& a, int start, int end)
			{
				int lastParent = start;

				while (getLeftChild(lastParent) <= end)
				{
					int leftChild = getLeftChild(lastParent);
					int maxSwap = lastParent;
					if (a[maxSwap] < a[leftChild])
					{
						maxSwap = leftChild;
					}
					if (leftChild + 1 <= end)
					{
						maxSwap = a[maxSwap] < a[leftChild + 1] ? leftChild + 1 : maxSwap;
					}

					if (maxSwap == lastParent)
					{
						return; // root holds the largest element
					}

					std::swap(a[lastParent], a[maxSwap]);
					lastParent = maxSwap;
				}
			}

			static int getParent(const int& pos)
			{
				int returnVal = (pos - 1) / 2;
				return returnVal >= 0 ? returnVal : 0;
			}

			static int getLeftChild(const int& parentPos)
			{
				return 2 * parentPos + 1;
			}

		public:
			static void heapSort(std::vector<int>& a) {
				if (a.size() <= 1)
				{
					return;
				}

				heapify(a);

				int end = a.size() - 1;
				while (end > 0)
				{
					removeTop(a, end);
					fixHeap(a, 0, end);
				}
			}
		};
		Heap::heapSort(a);
	}
}