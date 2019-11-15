/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
    // dp:假设我们得到了dp[i-1]的解的个数，如果当前不是0，那么我们可以把该数字单独拆出来
    // 放到每个dp[i-1]的解里就得到了dp[i-1]个解。
    // 此外，如果当前数字能与前一位数字组成大于等于10小于等于26的数字，那么可以把组合放到
    // dp[i-2]的解里，那么就得到了dp[i-2]个解
    // dp[i] = dp[i-1] + dp[i-2]
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i) {
            dp[i] = ('0' == s[i-1]) ? 0 : dp[i-1];

            if(i > 1 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))) {
                dp[i] += dp[i-2];
            }
        }

        return dp[n];
    }
};
// @lc code=end

