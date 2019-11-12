/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        const int M = haystack.size();
        const int N = needle.size();
        for(int i = 0; i <= M - N; ++i) {
            int j = 0;
            int tmp = i;
            while(j < N && haystack[tmp] == needle[j]) {
                ++j;
                ++tmp;
            }

            if(j == N) return i;
        }
        return -1;
    }
};
// @lc code=end

