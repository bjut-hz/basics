/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", n, n);
        return res;
    }

    void helper(vector<string>& res, string out, int left, int right) {
        if(left > right) return;

        if(0 == left && 0 == right) {
            res.push_back(out);
        } else {
            if(left > 0) {
                helper(res, out + '(', left - 1, right);
            }

            if(right > 0) {
                helper(res, out + ')', left, right - 1);
            }
        }
    }
};
// @lc code=end

