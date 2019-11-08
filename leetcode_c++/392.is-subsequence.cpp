/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    // bool isSubsequence(string s, string t) {
    //     int i = 0;
    //     int j = 0;
    //     const int S = s.size();
    //     const int T = t.size();

    //     while(i < S && j < T) {
    //         if(s[i] == t[j]) {
    //             ++i;
    //             ++j;
    //         } else {
    //             ++j;
    //         }
    //     }

    //     return i == S;
    // }

    // 子序列中的字符是有前后关系的，需要保持这个前后关系
    bool isSubsequence(string s, string t) {
        map<char, vector<int>> dict;
        for(int i = 0; i < t.size(); ++i) {
            dict[t[i]].push_back(i);
        }
        int pre = -1;
        for(int i = 0; i < s.size(); ++i) {
            auto iter = upper_bound(dict[s[i]].begin(), dict[s[i]].end(), pre);
            if(iter == dict[s[i]].end()) {
                return false;
            }
            pre = *iter;
        }

        return true;
    }
};
// @lc code=end

