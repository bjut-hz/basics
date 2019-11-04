/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, - 1);
        
        const int N = nums.size();
        if(0 == N) return ans;
        int left = 0, right = N - 1;
        
        while(left < right) { // right stand for left most number equal to target
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if(nums[right] != target) return ans;
        ans[0] = right;
        
        right = N; // the left most number bigger than target
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        ans[1] = right - 1;
        return ans;
    }
};
// @lc code=end

