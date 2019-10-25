/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& out, vector<int>& nums, int start) {
        res.push_back(out);

        for(int i = start; i < nums.size(); ++i) {
            out.push_back(nums[i]);
            helper(res, out, nums, i + 1);
            out.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> out;
        sort(nums.begin(), nums.end());
        helper(ans, out, nums, 0);
        return ans;
    }
};
// @lc code=end

