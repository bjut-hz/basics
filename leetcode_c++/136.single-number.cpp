/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int res = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            res ^= nums[i];
        }
        
        return res;
    }
};
// @lc code=end

