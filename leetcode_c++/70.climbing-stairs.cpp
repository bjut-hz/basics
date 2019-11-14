/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    // DP[i] = DP[i-1] + DP[i-2]
    int climbStairs(int n) {
        if(n <= 1) return 1;
        
        int a = 1, b = 1, c = 0;
        for(int i = 2; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
};
// @lc code=end

