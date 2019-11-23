/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    // int findDuplicate(vector<int>& nums) {
    //     int left = 1;
    //     int right = nums.size() - 1;

    //     while(left < right) {
    //         int mid = left + (right - left) / 2;
    //         int cnt = 0;
    //         for(auto& num : nums) {
    //             if(num <= mid) {
    //                 ++cnt;
    //             }
    //         }

    //         if(cnt <= mid) {
    //             left = mid + 1;
    //         } else {
    //             right = mid;
    //         }
    //     }

    //     return left;
    // }

    // 142.linked-list-cycle-ii
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        for(;;) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(fast == slow) break;
        }

        // 查找环的起点
        slow = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
// @lc code=end

