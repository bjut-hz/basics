/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    // // divide and conquer
    // int majorityElement(vector<int>& nums) {
    //     return majorityElement(nums, 0, nums.size() - 1);
    // }
    // int majorityElement(vector<int>& nums, int l, int r) {
    //     if(l >= r) return nums[l];
    //     int mid = l + (r - l) / 2;
    //     int leftNum = majorityElement(nums, l, mid);
    //     int rightNum = majorityElement(nums, mid + 1, r);

    //     if(leftNum == rightNum) {
    //         return leftNum;
    //     } else {
    //         int leftCnt = 0;
    //         for(int i = l; i <= mid; ++i) {
    //             if(nums[i] == leftNum) {
    //                 ++leftCnt;
    //             }
    //         }

    //         int rightCnt = 0;
    //         for(int i = mid + 1; i <= r; ++i) {
    //             if(nums[i] == rightNum) {
    //                 ++rightCnt;
    //             }
    //         }

    //         return leftCnt > rightCnt ? leftNum : rightNum;
    //     }
    // }

    // Boyer-Moore Voting Algorithm 多数投票算法
    int majorityElement(vector<int>& nums) {
        int res = 0;
        int cnt = 0;
        for(auto& num : nums) {
            if(cnt == 0) {
                res = num;
            }

            cnt = res == num ? ++cnt : --cnt;
        }
        return res;
    }
};
// @lc code=end

