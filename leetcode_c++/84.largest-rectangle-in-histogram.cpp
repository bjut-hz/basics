/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    // 使用单调递增栈,注意处理到栈里的某个元素的时候,还在栈里的元素与该元素之间的值都是大于该元素的而且，其后的到待处理的i位置的元素也是大于该元素的
    // 比如实例中在处理元素1的时候，那么此前处理的栈中的元素都是大于1,并且其后已经处理的元素也是大于该值的
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

