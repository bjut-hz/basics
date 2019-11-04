/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    // int trap(vector<int>& height) {
    //     stack<int> stk;
    //     int res = 0;
    //     for(int i = 0; i < height.size();) {
    //         if(stk.empty() || height[i] <= height[stk.top()]) {
    //             stk.push(i++);
    //         } else {
    //             int t = stk.top();
    //             stk.pop();
    //             if(!stk.empty()) {
    //                 res += (min(height[i], height[stk.top()]) - height[t]) * (i - stk.top() - 1);
    //             }
    //         }
    //     }

    //     return res;
    // }
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int res = 0;
        while(l < r) {
            // 左右指针，找出小的，如果比最小的小说明就能存水
            if(height[l] < height[r]) {
                int tmp = height[l];
                ++l;
                while(l < r && height[l] < tmp) {
                    res += tmp - height[l++];
                }
            } else {
                int tmp = height[r];
                --r;
                while(l < r && height[r] < tmp) {
                    res += tmp - height[r--];
                }
            }
        }

        return res;
    }
};
// @lc code=end

