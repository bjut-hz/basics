/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (target == nums[mid]) { 
				return mid; 
			} 

			if (nums[mid] <= nums[right]) {// right part is in order
				if (nums[mid] < target && target <= nums[right]) { left = mid + 1; }
				else right = mid - 1;
			} else {
				if (nums[left] <= target && target < nums[mid]) { right = mid - 1; }
				else left = mid + 1;
			}
		}
		
		return -1;
	}
};

