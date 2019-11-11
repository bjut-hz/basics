/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        const int N = s.size();
        int i = 0;
        int res = 0;
        while(i < N) {
            if(i + 1 < N && roman[s[i+1]] > roman[s[i]]) {
                res += roman[s[i+1]] - roman[s[i]];
                i += 2;
            } else {
                res += roman[s[i]];
                ++i;
            }
        }

        return res;
    }
};
// @lc code=end

