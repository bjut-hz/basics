/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int M = board.size();
        if(M == 0) return;

        const int N = board[0].size();
        if(N == 0) return;

        for(int i = 0; i < N; ++i) {
            if(board[0][i] == 'O') {
                helper(board, 0, i);
            }

            if(board[M - 1][i] == 'O') {
                helper(board, M - 1, i);
            }
        }

        for(int i = 0; i < M; ++i) {
            if(board[i][0] == 'O') {
                helper(board, i, 0);
            }

            if(board[i][N - 1] == 'O') {
                helper(board, i, N - 1);
            }
        }

        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(board[i][j] != '$') {
                    board[i][j] = 'X';
                } else {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void helper(vector<vector<char>>& board, int i, int j) {
        const int M = board.size();
        const int N = board[0].size();

        if(i < 0 || i >= M || j < 0 || j >= N) return;

        if(board[i][j] == 'O') {
            board[i][j] = '$';
        } else {
            return;
        }

        helper(board, i - 1, j);
        helper(board, i + 1, j);
        helper(board, i, j - 1);
        helper(board, i, j + 1);
    }
};
// @lc code=end

