/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1) return nums.size();

		size_t i = 1;
		for (auto& num : nums) {
			if (num != nums[i - 1]) {
				nums[i++] = num;
			}
		}
		return i;
	}
};

