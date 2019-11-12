/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
	string countAndSay(int n) {
		if (1 == n) return "1";

		string ans = "1";
		for (int i = 1; i < n; ++i) {
			string tmp;
			int j = 0;
			while (j < ans.size()) {
				int cnt = 1;
				char ch = ans[j];
				while (j + 1 < ans.size() && ans[j] == ans[j + 1]) {
					++cnt;
					++j;
				}

				tmp += to_string(cnt) + ch;
				++j;
			}

			ans = tmp;
		}

		return ans;
	}
};
// @lc code=end

