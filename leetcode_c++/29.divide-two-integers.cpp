/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
		if (divisor == 0) return INT_MAX;

		if (dividend == INT_MIN && divisor == -1) return INT_MAX;

		bool is_negative = false;
		if ((dividend ^ divisor) < 0) {
			is_negative = true;
		}


		long long m = dividend;
		long long n = divisor;

		if (m < 0) {
			m = -m;
		}
		if (n < 0) {
			n = -n;
		}

		if (m < n) return 0;

		long long ans = 0;
		while (m >= n) {
			long long t = n;
			long long p = 1;
			while (m > (t << 1)) {
				t <<= 1;
				p <<= 1;
			}
			ans += p;
			m -= t;
		}

		if (is_negative) {
			ans = -ans;
		}
		return ans;
	}
};
// @lc code=end

