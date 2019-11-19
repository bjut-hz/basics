/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
		for(auto& ch : s) {
			res = res * 26 + (ch - 'A' + 1);
		}
		return res;
    }
};
// @lc code=end

