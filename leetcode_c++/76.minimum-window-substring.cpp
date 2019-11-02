/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
	string minWindow(string s, string t) {
		int l = INT_MAX;
		string ans;
		vector<int> v(128, 0);
		for (auto& ch : t) {
			++v[ch];
		}

        int cnt = 0;
		for (int i = 0, j = 0; j < s.size(); ++j) {
            if(--v[s[j]] >= 0) {
                ++cnt;
            }

            while(cnt == t.size()) {
                if(j - i + 1 < l) {
                    l = j - i + 1;
                    ans = s.substr(i, l);
                }
                if(++v[s[i]] > 0) {
                    --cnt;
                } 
                // move left index to find small substring
                ++i;
            }
		}
		return ans;
	}
};
// @lc code=end

