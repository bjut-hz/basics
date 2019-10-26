/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        const int N = nums.size();
        int left = 0;
        int right = N - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return true;

            if(nums[mid] < nums[right]) {
                if(nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else if(nums[mid] > nums[right]) {
                if(nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                --right;
            }
        }

        return false;
    }
};
// @lc code=end

