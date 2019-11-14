/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        
        const int M = matrix.size();
        const int N = matrix[0].size();
        bool row_flag = false, col_flag = false;
        for(int i = 0; i < M; ++i) {
            if(matrix[i][0] == 0) {
                row_flag = true;
            }
        }

        for(int i = 0; i < N; ++i) {
            if(matrix[0][i] == 0) {
                col_flag = true;
            }
        }

        for(int i = 1; i < M; ++i) {
            for(int j = 1; j < N; ++j) {
                if(0 == matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1; i < M; ++i) {
            for(int j = 1; j < N; ++j) {
                if(0 == matrix[0][j] || 0 == matrix[i][0]) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(row_flag) {
            for(int i = 0; i < M; ++i) {
                matrix[i][0] = 0;
            }
        }

        if(col_flag) {
            for(int i = 0; i < N; ++i) {
                matrix[0][i] = 0;
            }
        }
    }
};
// @lc code=end

