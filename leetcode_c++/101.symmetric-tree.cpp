/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        if(NULL == root) return true;
        return helper(root->left, root->right);
    }

    bool helper(TreeNode* left, TreeNode* right) {
        if(NULL == left) return NULL == right;
        if(NULL == right) return NULL == left;

        if(left->val != right->val) return false;

        return helper(left->right, right->left) && helper(left->left, right->right);
    }
};
// @lc code=end

