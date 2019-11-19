/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp = nums;
        for(int i = 0; i < nums.size(); ++i) {
            nums[(i + k) % nums.size()] = tmp[i];
        }
    }
};
// @lc code=end

