/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
class Solution {
public:
	void BackTrack(set<string>& result, string& res,  int n, int level) {
		if (level == n) {
			result.insert(res);
			return;
		}

		for (int i = 0; i < res.size(); ++i) {
			res.insert(i, "()");
			BackTrack(result, res, n, level + 1);
			res.erase(i, 2);
		}
	}

	vector<string> generateParenthesis(int n) {
		if (0 == n) return {};

		set<string> filter;
		string res = "()";
		BackTrack(filter, res, n, 1);

		vector<string> result;
		for (auto& str : filter) {
			result.push_back(str);
		}

		return result;
	}
};


