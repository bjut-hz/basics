/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counter(26, 0);
        int start = 0;
        int max_cnt = 0;
        int res = 0;

        for(int i = 0; i < s.size(); ++i) {
            max_cnt = max(max_cnt, ++counter[s[i] - 'A']);

            while(i - start + 1 - max_cnt > k) {
                --counter[s[start] - 'A'];
                ++start;
            }
            if(i - start + 1 > res) {
                res = i - start + 1;
            }
        }
        return res;
    }
};
// @lc code=end

