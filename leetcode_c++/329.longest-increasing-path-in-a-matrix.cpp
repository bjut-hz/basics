/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (41.51%)
 * Likes:    1332
 * Dislikes: 22
 * Total Accepted:    110.8K
 * Total Submissions: 267.1K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 * 
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = 
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ] 
 * Output: 4 
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = 
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ] 
 * Output: 4 
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 * 
 * 
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0)); // dp[i][j]表示i,j位置上最大递增序列长度

        int res = 1;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                res = max(res, dfs(matrix, i, j, dp));
            }
        }

        return res;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
        if(dp[i][j]) return dp[i][j];
        int mx = 1;
        for(auto& dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            if(x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[i][j] < matrix[x][y]) {
                mx = max(mx,  1 + dfs(matrix, x, y, dp));
            }
        }

        dp[i][j] = mx;
        return dp[i][j];
    }
};
// @lc code=end

