/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (51.37%)
 * Likes:    1602
 * Dislikes: 96
 * Total Accepted:    139.5K
 * Total Submissions: 271.6K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 * 
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 * 
 * 
 * Example:
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * return 13.
 * 
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n^2.
 */

// @lc code=start
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		// 用最大堆
		priority_queue<int, vector<int>, less<int>> p;

		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				if (p.size() < k) {
					p.push(matrix[i][j]);
				} else {
					if (matrix[i][j] < p.top()) {
						p.pop();
						p.push(matrix[i][j]);
					}
				}
			}
		}

		return p.top();
	}

    // 用二分法
};
// @lc code=end

