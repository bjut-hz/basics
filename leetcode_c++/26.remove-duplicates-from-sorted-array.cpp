/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int i = 0;
        int j = 0;
        for(i = 0, j = 1; j < nums.size(); ++j) {
            if(nums[j] != nums[i]) {
                nums[++i] = nums[j];
            }
        }
        
        return i + 1;
    }
};
// @lc code=end

