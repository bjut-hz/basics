/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    // 设dp[i]为到第i户能得到的钱的最大值
    // dp[i] = max( dp[i-2] + nums[i], nums[i-1] )
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(1 == nums.size()) return nums[0];

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }

        return dp.back();
    }
};
// @lc code=end

