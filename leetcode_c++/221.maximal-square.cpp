/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (34.64%)
 * Likes:    1823
 * Dislikes: 45
 * Total Accepted:    166.2K
 * Total Submissions: 479.5K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 */

// @lc code=start
class Solution {
public:
    // dp[i][j]表示位置i,j处正方形的最大边长
    // dp[i][j] = min(dp[i-1][j], dp[i-1][j], dp[i-1][j-1]) + 1, 当dp[i][j]为'1'时
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // init
        int len = 0;
        for(int i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            len = max(len, dp[i][0]);
        }

        for(int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j] == '1' ? 1 : 0;
            len = max(len, dp[0][j]);
        }

        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
                    len = max(len, dp[i][j]);
                }
            }
        }

        return len * len;
    }
};
// @lc code=end

