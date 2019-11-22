/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    // // dp: dp[i]表示结果
    // int numSquares(int n) {
    //     vector<int> dp(n + 1, INT_MAX);
    //     dp[0] = 0;
    //     dp[1] = 1;
    //     for(int i = 2; i <= n; ++i) {
    //         for(int j = 1; j * j <= i; ++j) {
    //             dp[i] = min(dp[i], dp[i - j*j] + 1);
    //         }
    //     }
        
    //     return dp[n];
    // }
    
    // 四平方和定理https://www.cnblogs.com/grandyang/p/4800552.html
    int numSquares(int n) {
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        for (int a = 0; a * a <= n; ++a) {
            int b = sqrt(n - a * a);
            if (a * a + b * b == n) {
                return !!a + !!b;
            }
        }
        return 3;
    }
};
// @lc code=end

