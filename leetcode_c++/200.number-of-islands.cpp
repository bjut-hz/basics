/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;

        const int M = grid.size();
        const int N = grid[0].size();
        int res = 0;

        vector<vector<bool>> visited(M, vector<bool>(N, false));
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(visited[i][j] == false && '1' == grid[i][j]) {
                    helper(grid, i, j, visited);
                    ++res;
                }
            }
        }

        return res;
    }

    void helper(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0' || visited[i][j] == true) {
            return;
        }

        visited[i][j] = true;

        helper(grid, i - 1, j, visited);
        helper(grid, i + 1, j, visited);
        helper(grid, i, j - 1, visited);
        helper(grid, i, j + 1, visited);
    }
};
// @lc code=end

