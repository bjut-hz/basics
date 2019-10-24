/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */

// @lc code=start
class Solution {
public:
    // brute force
    // int triangleNumber(vector<int>& nums) {
    //     auto validTriangle = [](int a, int b, int c) {
    //         return a + b > c && a + c > b && b + c > a;
    //     };

    //     int cnt = 0;
    //     const int N = nums.size();
    //     for(int i = 0; i < N; i++) {
    //         for(int j = i + 1; j < N; j++) {
    //             for(int k = j + 1; k < N; k++) {
    //                 if(validTriangle(nums[i], nums[j], nums[k])) {
    //                     ++cnt;
    //                 }
    //             }
    //         }
    //     }
    //     return cnt;
    // }

    // 利用数组有序性
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        int cnt = 0;

        for(int i = 0; i < N; ++i) {
            for(int j = i + 1; j < N; ++j) {
                int sum = nums[i] + nums[j];
                // 找到小于sum的最大值, 利用二分查找
                int left = j + 1;
                int right = N - 1;
                int mid = left + (right - left) / 2;
                while(left <= right) {
                    mid = left + (right - left) / 2;
                    if(nums[mid] < sum) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }

                cnt += right - j;
            }
        }
        return cnt;
    }
};
// @lc code=end

