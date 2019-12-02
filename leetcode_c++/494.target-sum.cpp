/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (46.03%)
 * Likes:    1764
 * Dislikes: 82
 * Total Accepted:    121.5K
 * Total Submissions: 263.8K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * ⁠
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.  
 * 
 * 
 * Example 1:
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array is positive and will not exceed 20. 
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // dp[i][j] 表示前i-1个数字中和为j的个数,方便初始化
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<map<int, int>> dp(n + 1);
        dp[0][0] = 1;
        for(int i = 0; i < n; ++i) {
            for(auto& ele : dp[i]) {
                int sum = ele.first;
                int cnt = ele.second;
                dp[i+1][sum + nums[i]] += cnt;
                dp[i+1][sum - nums[i]] += cnt;
            }
        }

        return dp[n][S];
    }
};
// @lc code=end

