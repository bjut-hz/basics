/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (45.17%)
 * Likes:    1712
 * Dislikes: 65
 * Total Accepted:    111.3K
 * Total Submissions: 246.5K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 * 
 * 
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
 * day)
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * 
 */

// @lc code=start
class Solution {
public:
    //buy[i]表示到第i天最后一个操作是买，此时的最大收益。
    //sell[i]表示到第i天最后一个操作是卖，此时的最大收益。

    // buy[i] = max(sell[i-2] - price, buy[i-1])
    // sell[i] = max(buy[i-1] + price, sell[i-1])
    int maxProfit(vector<int>& prices) {
        if(prices.empty() || prices.size() == 1) return 0;

        int n = prices.size();
        vector<int> buy(n, 0);
        vector<int> sell(n, 0);

        buy[0] = -prices[0];
        buy[1] = max(-prices[0], -prices[1]);

        sell[0] = 0; 
        sell[1] = max(buy[0] + prices[1], sell[0]);

        for(int i = 2; i < n; ++i) {
            buy[i] = max(sell[i-2] - prices[i], buy[i-1]);
            sell[i] = max(buy[i-1] + prices[i], sell[i-1]);
        }

        return sell[n-1];
    }
};
// @lc code=end

