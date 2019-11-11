/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string out = "";

        helper(res, out, digits, 0, dict);
        return res;
    }

    void helper(vector<string>& res, string& out, string& digits, int start, string dict[]) {
        if(start == digits.size()) {
            res.push_back(out);
            return;
        }
        char ch = digits[start];
        for(int i = 0; i < dict[ch - '2'].size(); ++i) {
            out.push_back(dict[ch - '2'][i]);
            helper(res, out, digits, start + 1, dict);
            out.pop_back();
        }
    }
};
// @lc code=end

