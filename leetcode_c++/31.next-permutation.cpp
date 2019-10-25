/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int N = nums.size();
        if(N <= 1) return;
        int k = N - 2;
        while(k >= 0 && nums[k] >= nums[k+1]) {
            --k;
        }
        if(k < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int l = 0;
        for(l = N - 1; l > k; --l) {
            if(nums[l] > nums[k]) {
                swap(nums[l], nums[k]);
                reverse(nums.begin() + k + 1, nums.end());
                return;
            }
        }
    }
};
// @lc code=end

