/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        vector<bool> visited(nums.size(), false);

        helper(res, out, nums, visited);

        return res;
    }

    void helper(vector<vector<int>>& res, vector<int>& out, vector<int>& nums, vector<bool>& visited) {
        if(out.size() == nums.size()) {
            res.push_back(out);
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(false == visited[i]) {
                out.push_back(nums[i]);
                visited[i] = true;
                helper(res, out, nums, visited);
                visited[i] = false;
                out.pop_back();
            }
        }
    }
};
// @lc code=end

