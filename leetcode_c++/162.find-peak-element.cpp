/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty()) return -1;

        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[mid + 1]) {
                left = mid + 1; // 因为数组两侧是无穷小的数,因此可以这样划分
            } else {
                right = mid;
            }
        }

        return right;
    }
};
// @lc code=end

