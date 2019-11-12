/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> cell(9, vector<bool>(9, false));

        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if('.' != ch) {
                    if(row[i][ch - '1'] || col[j][ch-'1'] || cell[3 * (i / 3) + (j / 3)][ch - '1']) {
                        return false;
                    }

                    row[i][ch - '1'] = true;
                    col[j][ch-'1'] = true;
                    cell[3 * (i / 3) + (j / 3)][ch - '1'] = true;
                } 
            }
        }

        return true;
    }
};
// @lc code=end

