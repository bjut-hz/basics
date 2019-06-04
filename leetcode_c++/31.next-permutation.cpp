/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
//	Find the largest index k such that nums[k] < nums[k + 1].If no such index exists, just reverse nums and done.
//	Find the largest index l > k such that nums[k] < nums[l].
//	Swap nums[k] and nums[l].
//	Reverse the sub - array nums[k + 1:].

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int k = 0;
		for (k = (int)nums.size() - 2; k >= 0 && nums[k] >= nums[k + 1]; --k) {}
		if (k < 0) {
			reverse(nums.begin(), nums.end());
			return;
		}

		for (int l = nums.size() - 1; l > k; --l) {
			if (nums[k] < nums[l]) {
				swap(nums[k], nums[l]);
				reverse(nums.begin() + k + 1, nums.end());
				return;
			}
		}

	}
};

