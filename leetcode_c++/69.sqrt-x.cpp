/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1) return x;

		int left = 1, right = x;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (mid == (x / mid)) {
				return mid;
			} else if (mid < (x / mid)) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		return right - 1;
	}
};
// @lc code=end

