/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty()) return true;

		int i = 0;
		int j = s.size() - 1;
		while (i < j) {
			if (!isalpha(s[i]) && !isdigit(s[i])) {
				i++;
				continue;
			}

			if (!isalpha(s[j]) && !isdigit(s[j])) {
				j--;
				continue;
			}

			if (s[i] == s[j] || toupper(s[i]) == toupper(s[j])) {
				i++;
				j--;
			} else {
				return false;
			}
		}

		return true;
	}
};
// @lc code=end

