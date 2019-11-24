/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (41.69%)
 * Likes:    3261
 * Dislikes: 74
 * Total Accepted:    284.3K
 * Total Submissions: 681.8K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 * 
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n^2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 */

// @lc code=start
class Solution {
public:
    // // dp[i]表示以i为结束的最大递增序列
    // int lengthOfLIS(vector<int>& nums) {
    //     if(nums.empty()) return 0;

    //     vector<int> dp(nums.size(), 1);
    //     int res = 1;
    //     for(int i = 1; i < nums.size(); ++i) {
    //         for(int j = 0; j < i; ++j) {
    //             if(nums[i] > nums[j]) {
    //                 dp[i] = max(dp[i], dp[j] + 1);

    //                 res = max(res, dp[i]);
    //             }
    //         }
    //     }

    //     return res;
    // }

    /*
        化时间复杂度到 O(nlgn) 的解法，这里用到了二分查找法，
        所以才能加快运行时间哇。思路是，先建立一个数组 ends，
        把首元素放进去，然后比较之后的元素，如果遍历到的新元素比 
        ends 数组中的首元素小的话，替换首元素为此新元素，
        如果遍历到的新元素比 ends 数组中的末尾元素还大的话，
        将此新元素添加到 ends 数组末尾(注意不覆盖原末尾元素)。
        如果遍历到的新元素比 ends 数组首元素大，比尾元素小时，
        此时用二分查找法找到第一个不小于此新元素的位置，
        覆盖掉位置的原来的数字，以此类推直至遍历完整个 nums 数组，
        此时 ends 数组的长度就是要求的LIS的长度，
        特别注意的是 ends 数组的值可能不是一个真实的 LIS，
        比如若输入数组 nums 为 {4, 2， 4， 5， 3， 7}，
        那么算完后的 ends 数组为 {2， 3， 5， 7}，
        可以发现它不是一个原数组的 LIS，只是长度相等而已，
        千万要注意这点

        input: [0, 8, 4, 12, 2]

        dp: [0]

        dp: [0, 8]

        dp: [0, 4]

        dp: [0, 4, 12]

        dp: [0 , 2, 12]
    */

   int lengthOfLIS(vector<int>& nums) {
       vector<int> v;
       for(auto& num : nums) {
           auto iter = lower_bound(v.begin(), v.end(), num);
           if(iter == v.end()) {
               v.push_back(num);
           } else {
               *iter = num;
           }
       }

       return v.size();
   }
};
// @lc code=end

