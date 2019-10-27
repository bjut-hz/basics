/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
    // DP: dp[k][i] = max(dp[k][i-1], prices[i] - prices[j] + dp[k-1][j-1]) j = [0, i-1]
    // dp[k][i] for k transactions on i-th day
    // int maxProfit(vector<int>& prices) {
    //     const int N = prices.size();
    //     if(0 == N) return 0;

    //     vector<vector<int>> DP(3, vector<int>(N, 0));
    //     for(int k = 1; k <= 2; ++k) {
    //         int min_ = prices[0];
    //         for(int i = 1; i < N; ++i) {
    //             min_ = min(min_, prices[i] - DP[k-1][i-1]);
    //             DP[k][i] = max(DP[k][i-1], prices[i] - min_);
    //         }
    //     }
    //     return DP[2][N-1];
    // }

    int maxProfit(vector<int>& prices) {
        int oneBuy = INT_MAX;
        int oneBuyOneSell = 0;
        int twoBuy = INT_MAX;
        int twoBuyTwoSell = 0;

        for(auto& price : prices) {
            oneBuy = min(oneBuy, price);
            oneBuyOneSell = max(oneBuyOneSell, price - oneBuy);

            twoBuy = min(twoBuy, price - oneBuyOneSell);
            twoBuyTwoSell = max(twoBuyTwoSell, price - twoBuy);
        }
        return twoBuyTwoSell;
    }
};
// @lc code=end

