/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
 
class Solution {
public:
    int min2(int a, int b) {
        return a > b ? b : a;
    }
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        size_t i = 0, j = height.size() - 1;
        while (i < j) {
            int area = min2(height[i], height[j]) * (j - i);
            if(area > maxArea) { maxArea = area; }

            if(height[i] < height[j]){
                ++i;
            } else {
                --j;
            }
        }
        return maxArea;
    }
};

