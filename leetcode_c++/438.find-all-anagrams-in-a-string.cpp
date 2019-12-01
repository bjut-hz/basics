/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (39.37%)
 * Likes:    1983
 * Dislikes: 151
 * Total Accepted:    162K
 * Total Submissions: 411.5K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given a string s and a non-empty string p, find all the start indices of p's
 * anagrams in s.
 * 
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 * 
 * The order of output does not matter.
 * 
 * Example 1:
 * 
 * Input:
 * s: "cbaebabacd" p: "abc"
 * 
 * Output:
 * [0, 6]
 * 
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of
 * "abc".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s: "abab" p: "ab"
 * 
 * Output:
 * [0, 1, 2]
 * 
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // time limited
	// vector<int> findAnagrams(string s, string p) {
	// 	vector<int> dict(128, 0);
	// 	for (auto ch : p) {
	// 		dict[ch]++;
	// 	}

	// 	int m = s.size();
	// 	int n = p.size();

	// 	vector<int> res;

	// 	for (int i = 0; i <= (m - n); ++i) {
    //         vector<int> tmp = dict;
    //         bool success = true;
    //         for(int j = i; j < i + n; ++j) {
    //             if(--tmp[s[j]] < 0) {
    //                 success = false;
    //                 break;
    //             }
    //         }
    //         if(success) {
    //             res.push_back(i);
    //         }
	// 	}
	// 	return res;
	// }

    // sliding window
    vector<int> findAnagrams(string s, string p) {
        vector<int> m(128, 0);
        for(auto& ch : p) {
            m[ch]++;
        }

        vector<int> res;
        int cnt = p.size(); // 待要匹配的字符个数
        int left = 0; 
        int right = 0;
        while(right < s.size()) {
            if(m[s[right++]]-- >= 1) {
                cnt--;
            }

            if(cnt == 0) {
                res.push_back(left);
            }

            if(right - left == p.size() && m[s[left++]]++ >= 0) {
                cnt++;
            }
        }
        return res;
    }
};
// @lc code=end

