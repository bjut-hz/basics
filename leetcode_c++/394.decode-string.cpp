/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (47.25%)
 * Likes:    2143
 * Dislikes: 115
 * Total Accepted:    148.2K
 * Total Submissions: 313.7K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * Examples:
 * 
 * 
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
	string decodeString(string s) {
		int i = 0;
		return decode(s, i);
	}

	// string decode(string& s, int& i) {
	// 	int cnt = 0;
	// 	string res = "";

	// 	while (i < s.size()) {
	// 		if (isdigit(s[i])) {
	// 			cnt = cnt * 10 + (s[i] - '0');
	// 			i++;
	// 		} else if (s[i] == '[') {
	// 			i++;
	// 			auto result = decode(s, i);

	// 			for (int i = 0; i < cnt; ++i) {
	// 				res += result;
	// 			}
	// 			cnt = 0;
	// 		} else if (s[i] == ']') {
	// 			i++;
	// 			return res;
	// 		} else {
	// 			res.push_back(s[i]);
	// 			i++;
	// 		}
	// 	}

	// 	return res;
	// }

	string decode(string& s, int& i) {
		string res = "";
		while(i < s.size() && s[i] != ']') {
			if(!isdigit(s[i])) {
				res.push_back(s[i]);
				i++;
			} else {
                int cnt = 0;
                while(isdigit(s[i])) {
                    cnt = cnt * 10 + (s[i] - '0');
                    i++;
                }
                // '['
                i++;
                auto result = decode(s, i);
                i++;
                for(int i = 0; i < cnt; ++i) {
                    res += result;
                }
            }

		}
		return res;
	}

	// use two stack
};
// @lc code=end

