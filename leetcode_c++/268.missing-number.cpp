/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    // // 用数组下标做标志
    // int missingNumber(vector<int>& nums) {
    //     const int N = nums.size();
    //     for(int i = 0; i < N; ++i) {
    //         while(i != nums[i] && nums[i] < N) {
    //             swap(nums[i], nums[nums[i]]);
    //         }
    //     }

    //     for(int i = 0; i < N; ++i) {
    //         if(i != nums[i]) {
    //             return i;
    //         }
    //     }

    //     return N;
    // }

    // 异或求解
    int missingNumber(vector<int>& nums) {
        const int N = nums.size();
        int res = 0;
        for(int i = 0; i <= N; ++i) {
            res ^= i;
        }

        for(auto& num : nums) {
            res ^= num;
        }

        return res;
    }
};
// @lc code=end

