/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
    // 注意矩阵的左下角跟右上角值的规律
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;

        const int M = matrix.size();
        const int N = matrix[0].size();

        // 左下角
        int m = M - 1;
        int n = 0;

        while(m >= 0 && n < N) {
            if(matrix[m][n] == target) {
                return true;
            } else if(matrix[m][n] > target) {
                m--;
            } else {
                n++;
            }
        }

        return false;
    }
};
// @lc code=end

