/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     if(nums.empty() || nums.size() == 1) return nums;

    //     const int N = nums.size();
    //     vector<int> left(N, 1);
    //     vector<int> right(N, 1);
    //     left[0] = nums[0];
    //     right[N - 1] = nums[N - 1];

    //     for(int i = 1; i < N; ++i) {
    //         left[i] = left[i-1] * nums[i];
    //     }
    //     for(int i = N - 2; i >= 0; --i) {
    //         right[i] = right[i+1] * nums[i];
    //     }

    //     nums[0] = right[1];
    //     nums[N - 1] = left[N - 2];
    //     for(int i = 1; i < N - 1; ++i) {
    //         nums[i] = left[i-1] * right[i+1];
    //     }

    //     return nums;
    // }

    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1) return nums;

        // res记录了该位置左边的所有值的乘积
        vector<int> res(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i) {
            res[i] = res[i-1] * nums[i - 1];
        }

        int right = 1;
        for(int i = nums.size() - 1; i >= 0; --i) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};
// @lc code=end

