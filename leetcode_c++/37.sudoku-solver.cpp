/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */
class Solution {
public:
    /*
        只需要判定当前数字是否合法，不需要判定这个数组是否为数独数组，因为之前加进的数字都是合法的
    */
	bool IsValid(vector<vector<char>>& board, int i, int j) {
		// row check
		for (int col = 0; col < 9; ++col) {
			if (col != j && board[i][col] == board[i][j]) {
				return false;
			}
		}

		// column check
		for (int row = 0; row < 9; ++row) {
			if (row != i && board[row][j] == board[i][j]) {
				return false;
			}
		}

		// square check
		for (int row = 3 * (i / 3); row < 3 * (i / 3) + 3; ++row) {
			for (int col = 3 * (j / 3); col < 3 * (j / 3) + 3; ++col) {
				if ((row != i || col != j) && board[row][col] == board[i][j]) {
					return false;
				}
			}
		}

		return true;
	}
    // 回溯法的原理在于一个一个元素的处理，如果不满足就回退。在这个问题中，就不用在BackTack里
    // 不能用for循环遍历每个元素就行处理，因为会导致元素被处理多次。。。。注意这种写法保证了每个元素被处理一次
	bool BackTrack(vector<vector<char>>& board, int row, int col) {
		if (row == 9) return true;
		if (col >= 9) return BackTrack(board, row + 1, 0);

		if (board[row][col] == '.') {
			for (int delta = 0; delta < 9; ++delta) {
				board[row][col] = char('1' + delta);

				// 实验每个可能的结果并在当前的数字下递归求解子问题
				if (IsValid(board, row, col) && BackTrack(board, row, col + 1)) {
					return true;
				}

				board[row][col] = '.';
			}
		}
		else {
			return BackTrack(board, row, col + 1);
		}

		return false;

	}

	void solveSudoku(vector<vector<char>>& board) {
		if (board.empty() || board.size() != 9 || board[0].size() != 9) return;
		BackTrack(board, 0, 0);
	}
};

