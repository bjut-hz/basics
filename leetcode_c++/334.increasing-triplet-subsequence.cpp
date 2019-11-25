/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (39.71%)
 * Likes:    1122
 * Dislikes: 107
 * Total Accepted:    115.1K
 * Total Submissions: 289.8K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given an unsorted array return whether an increasing subsequence of length 3
 * exists or not in the array.
 * 
 * Formally the function should:
 * 
 * Return true if there exists i, j, k 
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return
 * false.
 * 
 * Note: Your algorithm should run in O(n) time complexity and O(1) space
 * complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [5,4,3,2,1]
 * Output: false
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 用两个数字,分别记录最小值以及次最小值,后序遍历有比这俩值大的就组成了递增三元序列
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX;
        int b = INT_MAX;

        for(auto& num : nums) {
            if(num <= a) {
                a = num;
            } else if(num <= b) {
                b = num;
            } else {
                if(b != INT_MAX) {
                    return true;
                }
            }
        }

        return false;
    }
};
// @lc code=end

