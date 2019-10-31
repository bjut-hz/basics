/*
 * @lc app=leetcode id=794 lang=cpp
 *
 * [794] Valid Tic-Tac-Toe State
 */

// @lc code=start
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int turn = 0;
        vector<int> rows(3, 0); // 记录行数据信息，用于统计输赢
        vector<int> cols(3, 0);
        int diag = 0; //对角线
        int anti_diag = 0;

        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] == 'X') {
                    turn++;
                    rows[i]++;
                    cols[j]++;
                    if(i == j) {
                        diag++;
                    } 

                    if(i + j == 2) {
                        anti_diag++;
                    }
                } else if(board[i][j] == 'O') {
                    turn--;
                    rows[i]--;
                    cols[j]--;

                    if(i == j) {
                        diag--;
                    } 

                    if(i + j == 2) {
                        anti_diag--;
                    }
                }
            }
        }

        if(turn != 0 && turn != 1) return false;

        bool x_win = rows[0] == 3 || rows[1] == 3 || rows[2] == 3 
        || cols[0] == 3 || cols[1] == 3 || cols[2] == 3 || diag == 3 || anti_diag == 3;

        bool o_win = (rows[0] == -3 || rows[1] == -3 || rows[2] == -3 
        || cols[0] == -3 || cols[1] == -3 || cols[2] == -3 || diag == -3 || anti_diag == -3);

        if(o_win && 0 != turn) return false;
        if(x_win && 1 != turn) return false;

        return true;
    }
};
// @lc code=end

