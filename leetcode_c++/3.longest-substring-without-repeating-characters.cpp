/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    //     map<char, int> dict;
    //     int i = 0;
    //     int j = 0;
    //     int res = 0;
    //     for(j = 0; j < s.size();) {
    //         if(dict.find(s[j]) == dict.end()) {
    //             dict[s[j]] = 1;
    //             if(j - i + 1 > res) {
    //                 res = j - i + 1;
    //             }
    //             ++j;
    //         } else {
    //             dict.erase(dict.find(s[i]));
    //             ++i;
    //         }
    //     }
    //     return res;
    // }

    int lengthOfLongestSubstring(string s) { 
        map<char, int> dict;
        int i = 0;
        int j = 0;
        int res = 0;
        for(j = 0; j < s.size(); ++j) {
            i = max(i, dict[s[j]]);
            if(j - i + 1 > res) {
                res = j - i + 1;
            }

            dict[s[j]] = j + 1;
        }

        return res;
    }
};
// @lc code=end

