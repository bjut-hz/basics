/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        const int N = nums.size();
        int res = N == 0 ? 0 : 1;
        int cnt = res;
        for(int i = 1; i < N; ++i) {
            if(nums[i] > nums[i-1]) {
                ++cnt;
                res = cnt > res ? cnt : res;
            } else {
                cnt = 1;
            }
        }

        return res;
    }
};
// @lc code=end

