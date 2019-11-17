/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    // dp[i]表示[0,i)可以字串可以被拆分
    // 注意，需要考虑[0,j), [j,i)的可拆分性，需要考虑j到i的各种子串组合!!!
	bool wordBreak(string s, vector<string>& wordDict) {
		set<string> set(wordDict.begin(), wordDict.end());
		vector<bool> dp(s.size() + 1, false);

        dp[0] = true;// 处理空字符串,初始化,方便处理

        for(int i = 0; i < dp.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(dp[j] && set.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
		return dp.back();
	}
};
// @lc code=end

