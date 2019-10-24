/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int N = nums.size();
        for(int i = 0; i < N; ++i) {
            while(nums[i] > 0 && nums[i] - 1 < N && nums[i] != nums[nums[i]-1]) {
                    swap(nums[nums[i]-1], nums[i]);                    
            }
        }

        for(int i = 0; i < N; ++i) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }

        return N + 1;
    }
};
// @lc code=end

