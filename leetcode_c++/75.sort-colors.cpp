/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = -1;
        int r = nums.size();
        for(int j = 0; j < r;) {
            if(nums[j] == 0) {
                l = l + 1;
                swap(nums[l], nums[j]);
                ++j;
            } else if(nums[j] == 2) {
                r = r - 1;
                swap(nums[r], nums[j]);
            } else {
                ++j;
            }
        }
    }
};
// @lc code=end

