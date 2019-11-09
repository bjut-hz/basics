/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {
public:
	// 剥洋葱法，一层一层的去掉叶子节点，剩一或者两层即为结果
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

		vector<vector<int>> graph(n);
		for (auto& edge : edges) {
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}

		queue<int> q;
		for (int i = 0; i < n; ++i) {
			if (graph[i].size() == 1) {
				q.push(i);
			}
		}

		while (n > 2) {
			int tmp = q.size();
			n -= tmp;
			for(int i = 0; i < tmp; ++i) { // 删除本次所有叶子节点
				auto v = q.front();
				q.pop();

				int t = graph[v][0];
				auto iter = find(graph[t].begin(), graph[t].end(), v);
				graph[t].erase(iter); // must be one element

				if (graph[t].size() == 1) {
					q.push(t);
				}
			}
		}

		vector<int> res;
		while (!q.empty()) {
			res.push_back(q.front());
			q.pop();
		}

		return res;
	}
};
// @lc code=end

