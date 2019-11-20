/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
	bool isHappy(int n) {
		set<int> s;
		while (n != 1) {
			int sum = 0;
			while (n != 0) {
				sum += (n % 10) * (n % 10);
				n /= 10;
			}
			if (s.count(sum)) return false;
			s.insert(sum);
			n = sum;
		}
		return true;
	}
};
// @lc code=end

