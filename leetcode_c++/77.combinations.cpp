/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> out;
        helper(ans, out, n, 1, k);

        return ans;
    }

    void helper(vector<vector<int>>& ans, vector<int>& out, int n, int start, int cnt) {
        if(0 == cnt) {
            ans.push_back(out);
            return;
        }

        for(int i = start; i <= n; ++i) {
            out.push_back(i);
            helper(ans, out, n, i + 1, cnt - 1);
            out.pop_back();
        }
    }
};
// @lc code=end

