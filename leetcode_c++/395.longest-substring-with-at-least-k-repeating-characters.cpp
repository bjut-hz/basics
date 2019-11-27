/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (39.74%)
 * Likes:    959
 * Dislikes: 85
 * Total Accepted:    59.3K
 * Total Submissions: 149.2K
 * Testcase Example:  '"aaabb"\n3'
 *
 * 
 * Find the length of the longest substring T of a given string (consists of
 * lowercase letters only) such that every character in T appears no less than
 * k times.
 * 
 * 
 * Example 1:
 * 
 * Input:
 * s = "aaabb", k = 3
 * 
 * Output:
 * 3
 * 
 * The longest substring is "aaa", as 'a' is repeated 3 times.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s = "ababbc", k = 2
 * 
 * Output:
 * 5
 * 
 * The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is
 * repeated 3 times.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // int longestSubstring(string s, int k) {
    //     int res = 0;
    //     // 总共只有26个字母,对于每个长度种类的字母组合检查所有的子串
    //     for(int i = 1; i <= 26; ++i) {
    //         // sliding window
    //         int left = 0;
    //         int right = 0;
    //         vector<int> char_cnt(26, 0);
    //         int unique_cnt = 0;

    //         while(right < s.size()) {
    //             bool valid = true;
    //             if(char_cnt[s[right++] - 'a']++ == 0) {
    //                 unique_cnt++;
    //             }

    //             while(unique_cnt > i) {
    //                 if(--char_cnt[s[left++] - 'a'] == 0) {
    //                     --unique_cnt;
    //                 }
    //             }

    //             // 检查合法性
    //             for(auto& cnt : char_cnt) {
    //                 if(cnt > 0 && cnt < k) {
    //                     valid = false;
    //                 }
    //             }

    //             if(valid) {
    //                 res = max(res, right - left);
    //             }
    //         }
    //     }

    //     return res;
    // }


    // 递归的思想是，首先统计整个字符串各个字符出现的次数,如果某个字符少于k次,那么
    // 最后的结果肯定是不包含该字符的,肯定是在该字符之前的子串或者之后的子串
    // divide and conquer
    int longestSubstring(string s, int k) {
        vector<int> cnt(26, 0);
        for(auto& ch : s) {
            cnt[ch - 'a']++;
        }

        int res = 0;
        bool ok = true;
        int max_idx = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(cnt[s[i] - 'a'] < k) {
                // 此时不能包含第i个字母了
                ok = false;
                res = max(res, longestSubstring(s.substr(max_idx, i - max_idx), k));
                max_idx = i + 1;
            }
        }

        return ok ? s.size() : max(res, longestSubstring(s.substr(max_idx), k));
    }
};
// @lc code=end

