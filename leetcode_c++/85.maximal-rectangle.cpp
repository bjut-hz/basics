/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (35.23%)
 * Likes:    1902
 * Dislikes: 55
 * Total Accepted:    144K
 * Total Submissions: 408.7K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // 方便处理最后一个元素

        int area = 0;
        stack<int> stk;
        for(int i = 0; i < heights.size(); ++i) {
            while(!stk.empty() && heights[stk.top()] > heights[i]) {
                int cur = stk.top();
                stk.pop();

                area = max(area, heights[cur] * (stk.empty() ? i : (i - stk.top() - 1)));
            }
            stk.push(i);
        }

		heights.pop_back();
        return area;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

		int m = matrix.size();
		int n = matrix[0].size();
		vector<int> heights(n, 0);
		int area = 0;
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				heights[j] = matrix[i][j] == '0' ? 0 : (heights[j] + 1);
			}
			area = max(area, largestRectangleArea(heights));
		}
		return area;
    }
};
// @lc code=end

