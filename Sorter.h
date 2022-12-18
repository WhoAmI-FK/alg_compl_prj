#pragma once
#include "SorterIf.h"

namespace __sorting {

	class Sorter : public SorterIf
	{
	public:
		void sort(std::vector<int>& a, SortingTypes selectedType) override;

		void insertionSort(std::vector<int>& a);

		void heapSort(std::vector<int>& a);

		void mergeSort(std::vector<int>& a);

		void quickSort(std::vector<int>& a);

		void print(std::vector<int>& a);
	private:
		void mergeSort(std::vector<int>& a, std::size_t left, std::size_t right);
		void helperMergeArray(std::vector<int>& a, std::size_t leftStart, std::size_t rightEnd);
		void quickSort(std::vector<int>& a, int left, int right);
		int hoaresPartition(std::vector<int>& a, int left, int right);
	};

};