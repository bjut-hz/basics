/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> flag(n, true);
        int res = 0;
        for(int i = 2; i < n; ++i) {
            if(flag[i]) {
                res++;
                for(int j = 2; i * j < n; ++j) {
                    flag[i*j] = false;
                }
            }
        }

        return res;
    }
};
// @lc code=end

