/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    // DP[i][j] = DP[i+1][j-1] + 2
    int longestValidParentheses(string s) {
        stack<int> st;
        int start = 0, res = 0, N = s.size(); // start是合法括号串的起始位置
        for(int i = 0; i < N; ++i) {
            if('(' == s[i]) {
                st.push(i);
            } else {
                if(st.empty()) {
                    start = i + 1;
                } else {
                    st.pop();
                    if(st.empty()) {
                        res = max(res, i - start + 1);
                    } else {
                        res = max(res, i - st.top());
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

