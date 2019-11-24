/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (32.56%)
 * Likes:    2512
 * Dislikes: 90
 * Total Accepted:    273.9K
 * Total Submissions: 840.8K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */

// @lc code=start
class Solution {
public:
    // dp[i]表示i找零所需最少的零钱数
    int coinChange(vector<int>& coins, int amount) {
        if(0 == amount) return 0;
        vector<long long> dp(amount + 1, INT_MAX);
        for(auto& coin : coins) {
            if(coin <= amount) {
                dp[coin] = 1;
            }
        }

        for(int i = 1; i <= amount; ++i) {
            for(auto& coin : coins) {
                if(i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1); // 尝试各种零钱组合
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
// @lc code=end

