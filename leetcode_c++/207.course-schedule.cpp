/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        const int N = numCourses;
        vector<int> indegree(N, 0);
        queue<int> q;

        map<int, vector<int>> graph;
        for(auto& p : prerequisites) {
            ++indegree[p[0]];

            graph[p[1]].push_back(p[0]);
        }

        for(int i = 0; i < N; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int counter = 0;
        while(!q.empty()) {
            auto v = q.front();
            q.pop();
            ++counter;

            for(auto& vertex : graph[v]) {
                --indegree[vertex];
                if(indegree[vertex] == 0) {
                     q.push(vertex);
                }
            }
        }

        return counter == N;
    }
};
// @lc code=end

