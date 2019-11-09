/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int N = nums.size();
        int max = 0;
        for(int i = 0; i < N && i <= max; ++i) {
            if(nums[i] + i >= max) {
                max = nums[i] + i;
                if(max >= N - 1) {
                    return true;
                }
            }
        } 

        return false;
    }
};
// @lc code=end

