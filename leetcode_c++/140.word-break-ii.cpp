/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string, vector<string>> m;
        return helper(s, wordDict, m);
    }
    // 递归实现的动态规划，先解决子问题得到子问题的解，然后把子问题解进行组合得到原问题的解，子问题求解时可以使用map加速。。
    // 使用map加速是带备忘录的自顶向下
    // 本题可以尝试根据递归公式组合得到问题的解:自底向上
    vector<string> helper(string s, vector<string>& wordDict, map<string, vector<string>>& m) {
        if(m.count(s)) return m[s];
        if(s.empty()) return {""};

        vector<string> res;
        for(auto& word : wordDict) {
            if(s.substr(0, word.size()) != word) {
                continue;
            }

            auto ans = helper(s.substr(word.size()), wordDict, m);
            for(auto& str : ans) {
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }

        m[s] = res;
        return res;
    }
};
// @lc code=end

