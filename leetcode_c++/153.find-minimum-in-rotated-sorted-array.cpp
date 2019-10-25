/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        const int N = nums.size();
        if(0 == N) return 0;

        int left = 0, right = N - 1;
        int mid = left + (right - left) / 2;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]) { 
               // 此时mid肯定不是最小的了
                left = mid + 1;
            } else {
                // 此时应该包含mid
                right = mid;
            }
        }

        return nums[right];
    }
};
// @lc code=end

