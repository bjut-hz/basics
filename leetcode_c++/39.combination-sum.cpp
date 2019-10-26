/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> out;
        helper(ans, candidates, out, 0, 0, target);
        return ans;
    }

    void helper(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& out, int start, int sum, int target) {
        if(sum == target) {
            ans.push_back(out);
        } else if(sum > target){
            return;
        }

        for(int i = start; i < candidates.size(); ++i) {
            out.push_back(candidates[i]);
            helper(ans, candidates, out, i, sum + candidates[i], target);
            out.pop_back();
        }
    }
};
// @lc code=end

