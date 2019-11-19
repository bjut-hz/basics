/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
public:
    // 求5的个数即可
    int trailingZeroes(int n) {
        int res = 0;
        while(n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};
// @lc code=end

