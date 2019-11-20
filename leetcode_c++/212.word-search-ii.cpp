/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Solution {
public:
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
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if (words.empty()) return ans;
		if (board.empty() || board[0].empty()) return ans;

		int m = board.size(), n = board[0].size();
        for(auto word : words) {
            bool res = false;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (board[i][j] == word[0] && res == false) {
                        vector<vector<bool>> visited(m, vector<bool>(n, false));
                        string out = "";
                        helper(board, visited, word, out, i, j, res);
                        if (res) {
                            ans.push_back(word);
                        }
                    }
                }
            }
        }

		return ans;
    }
};
// @lc code=end

