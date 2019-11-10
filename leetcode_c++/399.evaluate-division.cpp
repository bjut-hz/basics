/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution {
public:

	double solver(map<string, map<string, double>>& equations, string up, string down, set<string>& visited) {
		if (equations.count(up) == 0) return -1.0;

		if (equations[up].count(down)) {
			return equations[up][down];
		} else {
			for (auto tmp : equations[up]) {
				if (visited.count(tmp.first)) continue;

				visited.insert(tmp.first);
				auto result = solver(equations, tmp.first, down, visited);
				visited.erase(tmp.first);
                if (-1.0 != result) {
					return equations[up][tmp.first] * result;
				}
			}
		}

		return -1.0;
	}

	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		map<string, map<string, double>> equals;
		for (int i = 0; i < equations.size(); ++i) {
			auto e = equations[i];

			equals[e[0]][e[0]] = 1.0;
			equals[e[0]][e[1]] = values[i];

			equals[e[1]][e[1]] = 1.0;
			equals[e[1]][e[0]] = 1.0 / values[i];
		}

		vector<double> res;

		for (auto& query : queries) {
			set<string> visited;
			res.push_back(solver(equals, query[0], query[1], visited));
		}

		return res;
	}
};
// @lc code=end

