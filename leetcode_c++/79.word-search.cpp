/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty()) return false;
		if (board.empty() || board[0].empty()) return false;

		int m = board.size(), n = board[0].size();
		bool res = false;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (board[i][j] == word[0]) {
					vector<vector<bool>> visited(m, vector<bool>(n, false));
					string out = "";
					helper(board, visited, word, out, i, j, res);

					if (res) return true;
				}
			}
		}

		return false;
	}


	vector<vector<int>> dirs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
	void helper(vector<vector<char>>& board, vector<vector<bool>>& visited, const string& target, string& out, int i, int j, bool& res) {
		if (res) return;

		if (out.size() > 0) {
			int l = out.size() - 1;
			if (out[l] != target[l]) {
                return;
            } else if(out == target) {
                res = true;
                return;
            }
		}

		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j]) return;

		for (const auto& dir : dirs) {
            visited[i][j] = true;
            out.push_back(board[i][j]);
            helper(board, visited, target, out, i + dir[0], j + dir[1], res);
            out.pop_back();
            visited[i][j] = false;
		}
	}
};
// @lc code=end

