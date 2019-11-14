/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    /*
        在展开数组时，我们可以看到，我们按照的顺序是：

        向右->向下->向左->向上
        假如说一个矩阵是m*n的，那么，首先向右走m步，然后向下走n-1步；接着向左走m-1步，之后向上走n-2步。。。

        当我们发现需要走的步数为0时，自然就结束了。
    */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(0 == n) return {};
        int m = matrix[0].size();
        if(0 == m) return {};

        vector<int> res;
        vector<int> steps{m, n - 1};

        // 四个方向，分别为：右下左上
        vector<vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
        int dir = 0;
        int i_row = 0; 
        int i_col = -1; // 第一步的左侧一个元素
        while(steps[dir%2]) {
            for(int i = 0; i < steps[dir%2]; ++i) {
                i_col += dirs[dir][1];
                i_row += dirs[dir][0];
                res.push_back(matrix[i_row][i_col]);
            }

            steps[dir%2]--;
            dir = (dir + 1) % 4;
        }
        return res;
    }
};
// @lc code=end

