#include "sort.h"
#include "basic.h"

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