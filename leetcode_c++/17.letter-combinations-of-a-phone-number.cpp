/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
class Solution {
public:
	void BackTrack(string& digits, vector<string>& result, string& res, int index) {
		if (res.length() == digits.length()) {
			result.push_back(res);
			return;
		}

		int key = digits[index] - '0';
		for (int j = 0; j < digits_[key].length(); ++j) {
			res.push_back(digits_[key][j]);
			BackTrack(digits, result, res, index + 1);
			res.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {
		if (digits.empty()) return {};

		vector<string> result;
		string res = "";

		BackTrack(digits, result, res, 0);
		return result;
	}

private:
	string digits_[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
};


