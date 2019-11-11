/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
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

        return area;
    }
};
// @lc code=end

