/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int mx = max(p->val, q->val);
        int mn = min(p->val, q->val);

        if(mn > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        if(mx < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        return root;
    }
};
// @lc code=end

