/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		const int N = prices.size();
        int res = 0;
		for(int i = 1; i < N; ++i) {
			if(prices[i] - prices[i-1] > 0) {
				res += prices[i] - prices[i-1];
			}
		}
		return res;
    }
};
// @lc code=end

