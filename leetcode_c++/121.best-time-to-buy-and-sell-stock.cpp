/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
	// DP[i] = max(DP[i-1], (nums[i] - nums[k]) 0 <= k < i
    int maxProfit(vector<int>& prices) {
		int res = 0;
		int min = INT_MAX;

		for(auto& price : prices) {
			if(price < min) {
				min = price;
			}

			if(price - min > res) {
				res = price - min;
			}
		}
		return res;
    }
};
// @lc code=end

