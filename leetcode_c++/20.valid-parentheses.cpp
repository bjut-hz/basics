/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(auto& ch : s) {
            if('(' == ch || '[' == ch || '{' == ch) {
                stk.push(ch);
            } else {
                if(stk.empty()) {
                    return false;
                } else {
                    if(')' == ch && stk.top() != '(') {
                        return false;
                    }

                    if(']' == ch && stk.top() != '[') {
                        return false;
                    }

                    if('}' == ch && stk.top() != '{') {
                        return false;
                    }

                    stk.pop();
                }
            }
        }

        return stk.empty();
    }
};
// @lc code=end

