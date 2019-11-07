/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
    vector<TreeNode*> generateTrees(int start, int end) {
        if(start > end) {
            return {NULL};
        }
        vector<TreeNode*> ans;
        for(int i = start; i <= end; ++i) {
            auto left = generateTrees(start, i - 1);
            auto right = generateTrees(i + 1, end);

            for(auto& l : left) {
                for(auto& r : right) {
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    ans.push_back(node);
                }
            }
        }

        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(0 == n) return {};
        return generateTrees(1, n);
    }
};
// @lc code=end

