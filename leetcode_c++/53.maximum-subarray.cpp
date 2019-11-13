/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int sum = 0;
        for(auto& num : nums) {
            sum += num;
            res = max(res, sum);
            if(sum < 0) {
                sum  = 0;
            }
        }
        return res;
    }
};
// @lc code=end

