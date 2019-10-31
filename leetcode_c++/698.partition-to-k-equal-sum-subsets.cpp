/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
class Solution {
public:

    bool helper(vector<int>& nums, vector<bool>& visited, int start, int K, int sum, int target) {
        if(K == 1) return true;

        if(sum == target) {
            return helper(nums, visited, 0, K - 1, 0, target);
        }

        for(int i = start; i < nums.size(); ++i) {
            if(visited[i]) continue;

            visited[i] = true; // 需要记录哪些元素已被使用了
            if(helper(nums, visited, i + 1, K, sum + nums[i], target)) {
                return true;
            }
            visited[i] = false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;

        vector<bool> visited(nums.size(), false);
        return helper(nums, visited, 0, k, 0, sum / k);
    }
};
// @lc code=end

