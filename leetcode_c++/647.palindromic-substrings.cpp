/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (58.53%)
 * Likes:    1804
 * Dislikes: 93
 * Total Accepted:    134K
 * Total Submissions: 228.9K
 * Testcase Example:  '"abc"'
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 * 
 * Example 1:
 * 
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // dp[i][j]表示字符串[i,j]是否是一个回文子串
    // dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int cnt = 0;
        for(int i = 0; i < s.size(); ++i) {
            dp[i][i] = true;
            ++cnt;
            if(i + 1 < s.size() && s[i] == s[i+1]) {
                dp[i][i+1] = true;
                ++cnt;  
            } 
        }

        for(int j = 2; j < s.size(); ++j) {
            for(int i = j - 2; i >= 0; --i) {
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                if(dp[i][j]) {
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};
// @lc code=end

