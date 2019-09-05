#ifndef MAXIMUM_SUBARRAY_H_
#define MAXIMUM_SUBARRAY_H_

#include<vector>
#include<functional>

#include "basic.h"

namespace CLRS {
	class MaximumSubarraySolution{
		public:
		// brute force
		static int Solution1(std::vector<int>& nums) {
			int result = 0;
			for(int i = 0; i < nums.size(); ++i) {
				for(int j = i; j < nums.size(); ++j) {
					int sum = Sum(nums, i, j);
					result = sum > result? sum : result;
				}
			}
			return result;
		}

		// divide and conquer
		static int Solution2(std::vector<int>& nums) {
			auto Max3 = [](int a, int b, int c) {
				if(a >= b && a >= c) {return a;}
				if(b >= a && b >=c) {return b;}
				return c;
			}; 

			auto MaximumSubarray = Y(
				[&](auto&& self, std::vector<int>& nums, int l, int r) ->int {
					if (l > r) return 0;

					if(l == r){
						if(nums[l] == 0) {
							return nums[l];
						} else {
							return 0;
						}
					}
					
					int center = l + (r - l) / 2;
					int l_max = self(nums, l, center);
					int r_max = self(nums, center + 1, r);

					int l_border_sum = 0;
					int l_border_max = 0;
					for(int i = center; i >= l; --i) {
						l_border_sum += nums[i];
						if(l_border_sum > l_border_max) {
							l_border_max = l_border_sum;
						}
					}
					int r_border_sum = 0;
					int r_border_max = 0;
					for(int i = center + 1; i <= r; ++i) {
						r_border_sum += nums[i];
						if(r_border_sum > r_border_max) {
							r_border_max = r_border_sum;
						}
					}
					return Max3(l_max, r_max, l_border_max + r_border_max);
				}
			);

			return MaximumSubarray(nums, 0, nums.size() - 1);
		}

		// dynamic programming
		// DP[i] = max2(DP[i-1] + nums[i], nums[i])
		static int Solution3(std::vector<int>& nums) {
			int result = 0;
			int sum = 0; // DP[i]
			for(int i = 0; i < nums.size(); ++i) {
				sum += nums[i];
				if(sum > result) {
					result = sum;
				} else if(sum < 0) {
					sum = 0;
				}
			}
			return result;
		}
		private:
		// [l, r]
		static int Sum(std::vector<int>& nums, int l, int r) {
			int sum = 0;
			for(; l <= r; ++l) {
				sum += nums[l];
			}
			return sum;
		}
	};
} // namespace CLRS

#endif // MAXIMUM_SUBARRAY_H_