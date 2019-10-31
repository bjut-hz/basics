/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<TreeNode*> allPossibleFBT(int N) {
		if (1 == N) {
			return { new TreeNode(0) };
		}

		if (N % 2 == 0) return {};

		vector<TreeNode*> ans;
		for (int i = 0; i < N; ++i) {
			auto left = allPossibleFBT(i);
			auto right = allPossibleFBT(N - i - 1);

			for (auto& l : left) {
				for (auto& r : right) {
					auto node = new TreeNode(0);
					node->left = l;
					node->right = r;
					ans.push_back(node);
				}
			}
		}
		return ans;
	}
};
// @lc code=end

