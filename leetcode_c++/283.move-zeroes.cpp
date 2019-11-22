/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int j = 0, i = 0; j < nums.size(); ++j) {
            if(nums[j] != 0) {
                swap(nums[i++], nums[j]);
            }
        }
    }
};
// @lc code=end

