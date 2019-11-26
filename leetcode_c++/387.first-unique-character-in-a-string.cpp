/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (50.99%)
 * Likes:    1294
 * Dislikes: 91
 * Total Accepted:    350.1K
 * Total Submissions: 686.5K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> m;
        for(auto& ch : s) {
            m[ch]++;
        }

        for(int i = 0; i < s.size(); ++i) {
            if(m[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

