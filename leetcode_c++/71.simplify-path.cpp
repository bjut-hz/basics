/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
	string simplifyPath(string path) {
		stringstream ss(path);
		vector<string> sub_path;
		string tmp;

		while (getline(ss, tmp, '/')) {
			if (tmp == "." || tmp == "/" || tmp == "") continue;

			if (tmp == ".." && !sub_path.empty()) {
				sub_path.pop_back();
				
			} else if (tmp != "..") {
				sub_path.push_back(tmp);
			}
		}

		string ans;
		for (auto& s : sub_path) {
			ans += "/" + s;
		}
		return ans.empty() ? "/" : ans;
	}
};
// @lc code=end

