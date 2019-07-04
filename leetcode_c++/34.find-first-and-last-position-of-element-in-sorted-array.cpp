/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int l_idx = -1, r_idx = -1;

		int left = 0, right = nums.size() - 1;
		// find l_idx
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				if (mid - 1 >= left && nums[mid - 1] == nums[mid]) {
					right = mid - 1;
				}
				else {
					l_idx = mid;
					break;
				}
			}
			else if (nums[mid] < target){
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}

		// find r_idx
		left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				if (mid + 1 <= right && nums[mid + 1] == nums[mid]) {
					left = mid + 1;
				}
				else {
					r_idx = mid;
					break;
				}
			}
			else if (nums[mid] < target) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}

		return { l_idx, r_idx };
	}
};

