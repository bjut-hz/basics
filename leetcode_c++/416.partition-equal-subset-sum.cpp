/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (41.88%)
 * Likes:    1682
 * Dislikes: 51
 * Total Accepted:    122K
 * Total Submissions: 291.4K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 * 
 * Note:
 * 
 * 
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // dp[i]表示原数组是否可以取出若干个数字，其和为i
    // dp[i] = dp[i] || dp[i - nums[j]]
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(auto& num : nums) {
            // 需要保证每个num都只用1次
            for(int i = target; i - num >= 0; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
    }
};
// @lc code=end

