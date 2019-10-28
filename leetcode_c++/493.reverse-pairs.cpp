/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution {
public:
    // // brute force
    // int reversePairs(vector<int>& nums) {
    //     int ret = 0;
    //     for(int i = 0; i < nums.size(); ++i) {
    //         for(int j = i + 1; j < nums.size(); ++j) {
    //             long long a = nums[i];
    //             long long b = 2 * (long long)nums[j];
    //             ret = a > b ? ret + 1 : ret;
    //         }
    //     }
    //     return ret;
    // }

    // https://www.cnblogs.com/grandyang/p/6657956.html
    int reversePairs(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    int helper(vector<int>& nums, int l, int r) {
        if(l >= r) return 0;

        int mid = l + (r - l) / 2;
        int res = helper(nums, l, mid) + helper(nums, mid + 1, r);
        for(int i = l, j = mid + 1; i <= mid; ++i) { // 保证有序才能生效,才能在线性时间内解决
            while(j <= r && (nums[i] / 2.0) > nums[j]) {
                ++j;
            }
            res += j - (mid + 1);
        }
        sort(nums.begin() + l, nums.begin() + r + 1);
    
        return res;
    }
};
// @lc code=end

