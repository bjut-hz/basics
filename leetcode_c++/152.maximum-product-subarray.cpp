/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    // 使用dp，需要记录负值的最小值，因为乘以该值后最后得到的是正值
    // 设MAX[i]是以i为结束的最大乘积值,MIN[i]是以i为结束的最小乘积值
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN;
        int max_ending_here = 1;
        int min_ending_here = 1;

        for(auto& num : nums) {
            int new_max_ending_here = max(max_ending_here * num, max(min_ending_here * num, num));
            int new_min_ending_here = min(max_ending_here * num, min(min_ending_here * num, num));

            result = max(result, new_max_ending_here);
            result = max(result, new_min_ending_here);

            max_ending_here = new_max_ending_here;
            min_ending_here = new_min_ending_here;
        }

        return result;
    }
};
// @lc code=end

