/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(0 == nums.size()) return 0;
        
        int i = 0;
        for(int j = 0; j < nums.size(); ++j) {
            if(nums[j] != val) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};
// @lc code=end

