/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> out;
        helper(ans, out, k, n, 0, 1, 0);
        return ans;
    }

    void helper(vector<vector<int>>& ans, vector<int>& out, int k, int target, int sum, int test_num, int cnt) {
        if (sum > target) return;
        if(cnt >= k) {
            if(cnt == k && sum == target) {
                ans.emplace_back(out);
            }
            return;
        }

        for(int i = test_num; i < 10; ++i) {
            out.emplace_back(i);
            helper(ans, out, k, target, sum + i, i + 1, cnt + 1);
            out.pop_back();
        }
    }
};
// @lc code=end

