/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution {
public:
    // bool isMatch(string s, string p) {
    //     int i = 0, i_star = -1;
    //     int j = 0, j_star = -1;
    //     while(i < s.size() ) {
    //         if(j < p.size() && (s[i] == p[j] || p[j] == '?')) {
    //             i++;
    //             j++;
    //         } else if(j < p.size() && p[j] == '*') {
    //             j_star = j;
    //             j++;
    //             i_star = i;
    //         } else if(i_star >= 0) { // 此处找到*匹配的位置，然后重新做匹配，此处体现出了*可以匹配0个或者多个
    //             i = ++i_star;
    //             j = j_star + 1;
    //         } else {
    //             return false;
    //         }
    //     }

    //     while(j < p.size() && p[j] == '*') {
    //         ++j;
    //     }
    //     return j == p.size();
    // }

    // DP
    // dp[i][j] 表示 s[0, i-1], p[0, j-1]是否匹配
    // dp[i][j] = dp[i-1][j-1], if s[i-1] == p[j-1] || p[j-1] == '?'
    // dp[i][j] == dp[i][j-1],  if p[j-1] == '*', 匹配0次
    // dp[i][j] = dp[i-1][j],   if p[j-1] == '*', 匹配至少一次
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> dp(m+1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if('*' == p[j-1]) {
                    dp[i][j] = dp[i][j-1] || (i > 0 && dp[i-1][j]);
                } else {
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

