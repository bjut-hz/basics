/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.20%)
 * Likes:    2812
 * Dislikes: 73
 * Total Accepted:    165.7K
 * Total Submissions: 383.4K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 * 
 * Example 1:
 * 
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * 
 * 
 * 
 * Note:
 * 
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 用hash表建立从开始到当前子数组之和与其次数之间的映射关系
	int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int sum = 0;
        map<int, int> m;
        m[0] = 1;
        for(auto& num : nums) {
            sum += num;
            res += m[sum - k]; // 若存在,sum - k到sum数组之和为k
            ++m[sum];
        }
        return res;
	}
};
// @lc code=end

