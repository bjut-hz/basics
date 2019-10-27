/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    // DP[i][j]表示substr(i,j)是不是回文
    // DP[i][j] = DP[i+1][j-1] && s[i] == s[j]
    string longestPalindrome(string s) {
        const int N = s.size();
        if(0 == N) return "";

        vector<vector<bool>> DP(N, vector<bool>(N, false));
        int lIdx = 0;
        int len = 1;

        for(int i = 0; i < N; ++i) {
            DP[i][i] = true;
        }

        // 注意此处要保证用到的dp子问题已经求解
		for (int j = 1; j < N; ++j) {
			for (int i = 0; i < j; ++i) {
				if (j - 1 >= i + 1) {
					DP[i][j] = DP[i + 1][j - 1] && s[i] == s[j];
				} else {
					DP[i][j] = s[i] == s[j];
				}
				if (DP[i][j]) {
					if (j - i + 1 > len) {
						len = j - i + 1;
						lIdx = i;
					}
				}
			}
		}

        return s.substr(lIdx, len);
    }
};
// @lc code=end

