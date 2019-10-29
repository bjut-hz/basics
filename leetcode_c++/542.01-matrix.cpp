/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        const int M = matrix.size();
        if(0 == M) return {{}};
        const int N = matrix[0].size();

        vector<vector<int>> ans(M, vector<int>(N, 0));
        queue<pair<int,int>> q;

        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(matrix[i][j] == 1) {
                    ans[i][j] = INT_MAX;
                } else {
                    q.push(make_pair(i, j));
                }
            }
        }

        vector<vector<int>> direction = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
      
        while(!q.empty()) {
            pair<int,int> ele = q.front();
            q.pop();

            for(auto& dir : direction) {
                int x = ele.first + dir[0];
                int y = ele.second + dir[1];

                if(x >= 0 && x < M && y >= 0 && y < N) {
                    if(ans[x][y] != 0 && ans[ele.first][ele.second] + 1 < ans[x][y]) {
                        ans[x][y]= ans[ele.first][ele.second] + 1;
                        q.push(make_pair(x, y));
                    }
                }
            }
        }
  

        return ans;
    }
};
// @lc code=end

