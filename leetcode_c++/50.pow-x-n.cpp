/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        if(exp < 0) return 1 / pow(x, -exp);
        return pow(x, exp);
    }

    double pow(double x, long long n) {
        if(0 == n) return 1;

        double ans = pow(x, n / 2);
        if(n & 1 == 1) {
            return ans * ans * x;
        } else {
            return ans * ans;
        }
    }
};
// @lc code=end

