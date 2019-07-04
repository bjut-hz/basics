/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty() || target < nums[0]) return 0;
		if (target > nums[nums.size() - 1]) return nums.size();

		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			else if (nums[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}

		return left;
	}
};

