/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    // vector<string> generateParenthesis(int n) {
    //     vector<string> res;
    //     helper(res, "", n, n);
    //     return res;
    // }

    // void helper(vector<string>& res, string out, int left, int right) {
    //     if(left > right) return;

    //     if(0 == left && 0 == right) {
    //         res.push_back(out);
    //     } else {
    //         if(left > 0) {
    //             helper(res, out + '(', left - 1, right);
    //         }

    //         if(right > 0) {
    //             helper(res, out + ')', left, right - 1);
    //         }
    //     }
    // }

    // 在不同的位置插入"()"
	vector<string> generateParenthesis(int n) {
		set<string> s;
		helper(n, 1, "()", s);

		
		vector<string> ans;
		for (auto& str : s) {
			if (str.size() == 2 * n) {
				ans.push_back(str);
			}
		}
		return ans;
	}

	void helper(int n, int level, string out, set<string>& s) {
		if (s.count(out)) return;

		s.insert(out);

		for (int i = level; i < n; i++) {
			for (int j = 0; j < out.size(); ++j) {
				if (0 == j) {
					helper(n, level + 1, "()" + out, s);
				}

				if (j == out.size() - 1) {
					helper(n, level + 1, out + "()", s);
				} else {
					helper(n, level + 1, out.substr(0, j + 1) + "()" + out.substr(j + 1), s);
				}
			}
		}
	}
};
// @lc code=end

