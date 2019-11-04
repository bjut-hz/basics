/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        const int N = height.size();
        if(N < 2) return 0;
        
        int left = 0, right = N - 1;
        int max_area = INT_MIN;
        while(left < right) {
            int length = min(height[left], height[right]);
            if(length * (right - left) > max_area) {
                max_area = length * (right - left);
            }
            
            if(height[left] > height[right]) {
                --right;
            } else {
                ++left;
            }
        }
        
        return max_area;
    }
};
// @lc code=end

