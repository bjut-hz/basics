/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, i_star = -1;
        int j = 0, j_star = -1;
        while(i < s.size() ) {
            if(j < p.size() && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            } else if(j < p.size() && p[j] == '*') {
                j_star = j;
                j++;
                i_star = i;
            } else if(i_star >= 0) { // 此处找到*匹配的位置，然后重新做匹配，此处体现出了*可以匹配0个或者多个
                i = ++i_star;
                j = j_star + 1;
            } else {
                return false;
            }
        }

        while(j < p.size() && p[j] == '*') {
            ++j;
        }
        return j == p.size();
    }
};
// @lc code=end

