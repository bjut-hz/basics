/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& out, vector<int>& nums, int start) {
        res.push_back(out);

        for(int i = start; i < nums.size(); ++i) {
            // remove duplicate
            if(i > start && nums[i-1] == nums[i])  {
                continue;
            }
            out.push_back(nums[i]);
            helper(res, out, nums, i + 1);
            out.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> out;
        vector<vector<int>> ans;
        helper(ans, out, nums, 0);
        return ans;
    }
};
// @lc code=end

