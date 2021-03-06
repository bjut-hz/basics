#ifndef SORT_H_
#define SORT_H_

#include<vector>
#include "basic.h"

namespace CLRS {
	class sort{
		public:
		static void InsertionSort(std::vector<int>&);
		static void MergeSort(std::vector<int>&);
		static void BubbleSort(std::vector<int>&);
		static void HeapSort(std::vector<int>&);
		static void QuickSort(std::vector<int>&);
		static void CountingSort(std::vector<int>&);
		static void RadixSort(std::vector<int>&);
		static void BucketSort(std::vector<int>&);

		private:
		static void Merge(std::vector<int>&, std::vector<int>&, int, int, int);
		static void MSort(std::vector<int>&, std::vector<int>&, int, int);
	};
} // namespace CLRS

#endif // SORT_H_