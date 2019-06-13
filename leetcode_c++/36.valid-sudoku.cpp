/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		if (board.empty() || board[0].empty()) return false;

		int m = board.size();
		int n = board[0].size();

		vector<vector<bool>> row(m, vector<bool>(n, false));
		auto column = row;// value copy
		auto square = row;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				int index = board[i][j] - '1';
				if (index >= 0 && index <= 9) {
					if (row[i][index] || column[index][j] || square[(3 * (i / 3) + j / 3)][index]) {
						return false;
					}
					row[i][index] = true;
					column[index][j] = true;
					square[(3 * (i / 3) + j / 3)][index] = true;
				}
			}
		}

		return true;
	}
};

