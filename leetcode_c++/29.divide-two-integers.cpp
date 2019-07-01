/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */
// 用位运算以及减法实现求商
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (0 == divisor || (dividend == INT_MIN && divisor == -1)) return INT_MAX;

		int sign = (dividend ^ divisor) >= 0 ? 1 : -1;

		long long m = dividend, n = divisor;
		if (m < 0) m = -(m);
		if (n < 0) n = -(n);

		if (m < n) return 0;

		long long ans = 0;
		while (n <= m) {
			long long t = n;
			long long p = 1;
			while ((t << 1) < m) {
				t <<= 1;
				p <<= 1;
			}

			m -= t;
			ans += p;
		}

		return ans * sign;
	}
};

