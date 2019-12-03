/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (61.32%)
 * Likes:    1800
 * Dislikes: 55
 * Total Accepted:    104.7K
 * Total Submissions: 170.8K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 
 * Given a list of daily temperatures T, return a list such that, for each day
 * in the input, tells you how many days you would have to wait until a warmer
 * temperature.  If there is no future day for which this is possible, put 0
 * instead.
 * 
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76,
 * 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 * 
 * 
 * Note:
 * The length of temperatures will be in the range [1, 30000].
 * Each temperature will be an integer in the range [30, 100].
 * 
 */

// @lc code=start
class Solution {
public:
    // 使用单调递减栈
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        stack<int> stk;
        for(int i = 0; i < T.size(); ++i) {
            if(stk.empty() || T[stk.top()] >= T[i]) {
                stk.push(i);
            } else {
                int cur = stk.top();
                stk.pop();

                res[cur] = i - cur;
                --i; // 重新处理该元素,直至入栈
            }
        }

        return res;
    }
};
// @lc code=end

