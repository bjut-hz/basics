/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (44.04%)
 * Likes:    1531
 * Dislikes: 53
 * Total Accepted:    308.3K
 * Total Submissions: 700K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        vector<vector<int>> ans;
        vector<int> out;

        helper(nums, ans, out, visited);
        return ans;
    }

    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& out, vector<bool>& visited) {
        if(out.size() == nums.size()) {
            ans.emplace_back(out);
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(visited[i]) continue;

            if(i > 0 && nums[i-1] == nums[i] && !visited[i-1]) continue; // 如果处理同一层的遍历当中，需要跳过，否则就重复了
            
            visited[i] = true;
            out.push_back(nums[i]);
            helper(nums, ans, out, visited);
            out.pop_back();
            visited[i] = false;

        }
    }
};
// @lc code=end

