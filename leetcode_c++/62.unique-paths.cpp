/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    // DP[i][j] = DP[i][j-1] + DP[i-1][j]
    int uniquePaths(int m, int n) {
        if(n == 0 || m == 0) return 0;
        // DP init
        vector<vector<int>> DP(n, vector<int>(m, 0));

        for(int i = 0; i < n; ++i) {
            DP[i][0] = 1;
        }

        for(int j = 0; j < m; ++j) {
            DP[0][j] = 1;
        }

        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                DP[i][j] = DP[i][j-1] + DP[i-1][j];
            }
        }

        return DP[n-1][m-1];
    }
};
// @lc code=end

