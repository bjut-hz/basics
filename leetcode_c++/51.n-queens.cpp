/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:

    // 穷举是按行开始的，所以只需要检测该行以上的数据即可
    bool isValid(vector<string>& queens, int row, int col) {
        for(int i = 0; i < row; ++i) {
            if(queens[i][col] == 'Q') return false;
        }

        for(int i = row - 1, j = col -1; i >= 0 && j >= 0; --i, --j) {
            if(queens[i][j] == 'Q') return false;
        }

        for(int i = row - 1, j = col + 1; i >= 0 && j < queens.size(); --i, ++j) {
            if(queens[i][j] == 'Q') return false;
        }

        return true;
    }

    void helper(vector<vector<string>>& ans, vector<string>& queens, int cur_row) {
        int n = queens.size();
        if(n == cur_row) {
            ans.push_back(queens);
            return;
        }

        for(int i = 0; i < n; ++i) {
            if(isValid(queens, cur_row, i)) {
                queens[cur_row][i] = 'Q';
                helper(ans, queens, cur_row + 1);
                queens[cur_row][i] = '.';                
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> queens(n, string(n, '.'));
        helper(ans, queens, 0);
        return ans;
    }


};
// @lc code=end

