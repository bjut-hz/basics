/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 */

// @lc code=start
class Solution {
public:
	string countOfAtoms(string formula) {
		string res = "";
		int pos = 0;
		map<string, int> m = parse(formula, pos);
		for (auto a : m) {
			res += a.first + (a.second == 1 ? "" : to_string(a.second));
		}
		return res;
	}
	map<string, int> parse(string& str, int& pos) {
		map<string, int> res;
		while (pos < str.size()) {
			if (str[pos] == '(') {
				++pos;
				for (auto a : parse(str, pos)) res[a.first] += a.second;
			} else if (str[pos] == ')') {
				int i = ++pos;
				while (pos < str.size() && isdigit(str[pos])) ++pos;
				int multiple = stoi(str.substr(i, pos - i));
				for (auto a : res) res[a.first] *= multiple;
				return res;
			} else {
				int i = pos++;
				while (pos < str.size() && islower(str[pos])) ++pos;
				string elem = str.substr(i, pos - i);
				i = pos;
				while (pos < str.size() && isdigit(str[pos])) ++pos;
				string cnt = str.substr(i, pos - i);
				res[elem] += cnt.empty() ? 1 : stoi(cnt);
			}
		}
		return res;
	}
};


class Solution {
public:
	string countOfAtoms(string formula) {
		string res = "";
		int pos = 0;
		map<string, int> m = parse(formula);
		for (auto a : m) {
			res += a.first + (a.second == 1 ? "" : to_string(a.second));
		}
		return res;
	}
	map<string, int> parse(string str) {
		map<string, int> res;
		int pos = 0;
		while (pos < str.size()) {
			if (str[pos] == '(') {
				++pos;
				int i = pos;
				int cnt = 1;
				while (cnt > 0) {
					if (str[pos] == '(') {
						++cnt;
					} else if (str[pos] == ')') {
						--cnt;
					}
					++pos;
				}

				auto ret = parse(str.substr(i, pos - i - 1));

				int num_start = pos;
				while (pos < str.size() && isdigit(str[pos])) ++pos;
				int multiple = stoi(str.substr(num_start, pos - num_start));


				for (auto a : ret) {
					ret[a.first] *= multiple;
					res[a.first] += ret[a.first];
				}


			} else {
				int i = pos++;
				while (pos < str.size() && islower(str[pos])) ++pos;
				string elem = str.substr(i, pos - i);
				i = pos;
				while (pos < str.size() && isdigit(str[pos])) ++pos;
				string cnt = str.substr(i, pos - i);
				res[elem] += cnt.empty() ? 1 : stoi(cnt);
			}
		}
		return res;
	}
};
// @lc code=end

