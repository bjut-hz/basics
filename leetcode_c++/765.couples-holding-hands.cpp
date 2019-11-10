/*
 * @lc app=leetcode id=765 lang=cpp
 *
 * [765] Couples Holding Hands
 */

// @lc code=start
class Solution {
public:
    // 对于不满足条件的进行查找直接交换两个值
	// int minSwapsCouples(vector<int>& row) {
	// 	int cnt = 0;
	// 	for (int i = 0; i < row.size(); i = i + 2) {
	// 		if ((row[i] ^ 1) != row[i + 1]) {
	// 			for (int j = i + 2; j < row.size(); ++j) {
	// 				if ((row[i] ^ 1) == row[j]) {
	// 					row[j] = row[i + 1];
	// 					row[i + 1] = (row[i] ^ 1);
	// 					++cnt;
	// 				}
	// 			}
	// 		}
	// 	}

	// 	return cnt;
	// }

    // union find
    // 分成N/2个群组，每次处理两个元素，如果两个元素不是同一个群组，则把两个群组进行合并
    int minSwapsCouples(vector<int>& row) {
        const int N = row.size();
        vector<int> root(N);
        for(int i = 0; i < N; ++i) {
            root[i] = i;
        }

        int cnt = 0;
        for(int i = 0; i < N; i = i + 2) {
            // 如果两者相邻那么会在同一个群组内
            int m = find(root, row[i] / 2);
            int n = find(root, row[i+1] / 2);

            if(m != n) {
                root[n] = m; // 合并群组
                ++cnt;
            }
        }

        return cnt;
    }

    int find(vector<int>& root, int i) {
        return root[i] == i ? i : find(root, root[i]);
    }
};
// @lc code=end

