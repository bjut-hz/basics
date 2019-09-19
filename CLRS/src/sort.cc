#include "sort.h"
#include "basic.h"
#include<algorithm>
#include<assert.h>

namespace CLRS {
	void sort::InsertionSort(std::vector<int>& nums){
		for(int j = 1; j < nums.size(); ++j) {
			int P = nums[j];
			int i = j;
			for(; i - 1 >= 0 && P < nums[i-1]; --i) {
				nums[i] = nums[i-1];
			}
			nums[i] = P;
		}
	}

	void sort::MergeSort(std::vector<int>& nums) {
		std::vector<int> tmp(nums.size(), 0);

		MSort(nums, tmp, 0, nums.size() - 1);
	}

	void sort::BubbleSort(std::vector<int>& nums) {
		for(int i = 0; i < nums.size(); ++i) {
			for(int j  = nums.size() - 1; j >= i + 1; j--) {
				if(nums[j] < nums[j-1]) {
					std::swap(nums[j], nums[j-1]);
				}
			}
		}
	}

	void sort::HeapSort(std::vector<int>& nums) {
		auto Parent = [](int i) {return (i - 1) / 2;};
		auto Left = [](int i) {return 2 * i + 1;};
		auto Right = [](int i) { return 2 * i + 2;};

		auto MaxHeapify = Y(
			[&](auto&& self, std::vector<int>& nums, int i, int heap_size) -> void {
				auto l = Left(i);
				auto r = Right(i);
				int largest = i;
				if(l < heap_size && nums[l] > nums[largest]) {
					largest = l;
				}
				if(r < heap_size && nums[r] > nums[largest]) {
					largest = r;
				}
				if(largest != i) {
					std::swap(nums[i], nums[largest]);
					self(nums, largest, heap_size);
				}
			}
		
		); 


		auto BuildHeap = [&](std::vector<int>& nums, int heap_size) {
			for(int i = heap_size / 2; i >= 0; --i) {
				MaxHeapify(nums, i, heap_size);
			}
		};

		const int N = nums.size();
		int heap_size = N;
		BuildHeap(nums, N);
		for(int i = N - 1; i >= 1; --i) {
			std::swap(nums[i], nums[0]);
			heap_size -= 1;
			MaxHeapify(nums, 0, heap_size);
		}
	}

	void sort::QuickSort(std::vector<int>& nums) {
		auto Partition = [](std::vector<int>& nums, int l, int r) -> int {
			auto x = nums[r];
			auto i = l - 1;

			for(int j = l; j <= r - 1; ++j) {
				if(nums[j] <= x) { 
					// find the num smaller than x and put it in the right position
					// p <= k <= i, nums[k] <=x
					i = i + 1;
					std::swap(nums[i], nums[j]);
				}
			}
			std::swap(nums[i+1], nums[r]);
			return i + 1; // the position of pivot
		};

		auto RandomizedPartition = [&](std::vector<int>& nums, int l, int r) {
			auto i = std::rand() % (r - l + 1) + l;
			std::swap(nums[r], nums[i]);

			return Partition(nums, l, r);
		};

		auto QSort = Y(
			[&](auto&& self, std::vector<int>& nums, int l, int r) -> void {
				if(l < r) {
					auto pos = Partition(nums, l, r);
					self(nums, l, pos - 1);
					self(nums, pos + 1, r);
				}
			}
		);

		auto RandomizedQSort = Y(
			[&](auto&& self, std::vector<int>& nums, int l, int r) -> void {
				if(l < r) {
					auto pos = RandomizedPartition(nums, l, r);
					self(nums, l, pos - 1);
					self(nums, pos + 1, r);
				}
			}
		);

		//QSort(nums, 0, nums.size() - 1);
		RandomizedQSort(nums, 0, nums.size() - 1);
 	}


	void sort::CountingSort(std::vector<int>& nums) {
		if (nums.size() == 0) return;
		auto min_iter = std::min_element(nums.begin(), nums.end());
		auto max_iter = std::max_element(nums.begin(), nums.end());
		int minus_delta = 0;
		if(*min_iter < 0) {
			minus_delta -= *min_iter;
		}
		int K = *max_iter + minus_delta + 1;
		std::vector<int> C(K, 0);
		for(auto& ele : nums) {
			ele += minus_delta;
			C[ele] += 1;
		}

		//// C[i] now contains the number of elements less than or equal to i
		//std::vector<int> A(nums);
		//for(int i = 1; i < K; ++i) {
		//	C[i] += C[i-1];
		//}

		//for(int i = A.size() - 1; i >= 0; --i) {
		//	nums[C[A[i]] - 1] = A[i];
		//	C[A[i]] -= 1;
		//}

		// output the number order directly
		int index = 0;
		for (int i = 0; i < K; ++i) {
			while (C[i] > 0) {
				nums[index++] = (i - minus_delta);
				--C[i];
			}
		}
	}

	void sort::RadixSort(std::vector<int>& nums) {
		if (0 == nums.size()) return;

		auto max_iter = std::max_element(nums.begin(), nums.end());
		auto GetIntLen = [](int num) -> int {
			int base = 10;
			int len = 1;
			while(num / base) {
				++len;
				base *= 10;
			}
			return len;
		};

		const int d = GetIntLen(*max_iter);
		for(int i = 0; i < d; ++i) {
			// should use stable sort to maintain radix sort's stability
			std::stable_sort(nums.begin(), nums.end(), [&](const int& lhs, const int& rhs){
				int base = std::pow(10, i);
				int lhs_quotient = lhs / base;
				int lhs_remainer = lhs_quotient % 10;

				int rhs_quotient = rhs / base;
				int rhs_remainer = rhs_quotient % 10;
				
				return lhs_remainer < rhs_remainer;
			});
		}
	}

	void sort::Merge(std::vector<int>& nums, std::vector<int>& tmp, int l_pos , int r_pos, int r_end) {
		int l_end = r_pos - 1;
		int tmp_pos = l_pos;
		int num_elements = r_end - l_pos + 1;

		while(l_pos <= l_end && r_pos <= r_end) {
			if(nums[l_pos] <= nums[r_pos]) {
				tmp[tmp_pos++] = nums[l_pos++]; 
			} else {
				tmp[tmp_pos++] = nums[r_pos++];
			}
		}

		while(l_pos <= l_end) { tmp[tmp_pos++] = nums[l_pos++]; }
		while(r_pos <= r_end) { tmp[tmp_pos++] = nums[r_pos++]; }

		// copy back from tmp to nums
		for(int i = 0; i < num_elements; ++i) {
			nums[r_end] = tmp[r_end];
			--r_end;
		}
	}

	void sort::MSort(std::vector<int>& nums, std::vector<int>& tmp, int l, int r) {
		if(l < r) {
			int center = l + (r - l) / 2;
			MSort(nums, tmp, l, center);
			MSort(nums, tmp, center + 1, r);

			Merge(nums, tmp, l, center + 1, r);
		}
	}
} // namespace CLRS