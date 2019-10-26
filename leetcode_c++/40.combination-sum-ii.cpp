/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> out;

        helper(ans, candidates, out, 0, 0, target);
        return ans;
    }


    void helper(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& out, int start, int sum , int target) {
        if(sum > target) return;
        if(sum == target) {
            ans.emplace_back(out);
            return;
        }

        for(int i = start; i < candidates.size(); ++i) {
            if(i > start && candidates[i] == candidates[i - 1]) continue;
            out.emplace_back(candidates[i]);
            helper(ans, candidates, out, i + 1, sum + candidates[i], target);
            out.pop_back();
        }
    }
};
// @lc code=end

