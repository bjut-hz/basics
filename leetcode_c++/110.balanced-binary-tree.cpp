/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    // int height(TreeNode* root) {
    //     if(NULL == root) return 0;
    //     return 1 + max(height(root->left), height(root->right));
    // }
    // bool isBalanced(TreeNode* root) {
    //     if(root == NULL) return true;
    //     int l_h = height(root->left);
    //     int r_h = height(root->right);
    //     return abs(l_h - r_h) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    // }

    // int checkHeight(TreeNode* root) {
    //     if(NULL == root) return 0;
    //     int left = checkHeight(root->left);
    //     if(left == - 1) return -1;
    //     int right = checkHeight(root->right);
    //     if(right == - 1) return -1;

    //     if(abs(left - right) > 1) return -1;
    //     return 1 + max(left, right);
    // }
    // bool isBalanced(TreeNode* root) {
    //     if(checkHeight(root) == -1) return false;
    //     return true;
    // }

    // save height info into val
    void getHeight(TreeNode* root) {
        if(root == NULL) return;
        getHeight(root->left);
        getHeight(root->right);

        if(root->left && root->right) {
            root->val = max(root->left->val, root->right->val) + 1;
        } else if(root->left) {
            root->val = root->left->val + 1;
        } else if(root->right) {
            root->val = root->right->val + 1;
        } else {
            root->val = 1;
        }
    }
    bool helper(TreeNode* root) {
        if(root == NULL) return true;
        int left = root->left == NULL ? 0 : root->left->val;
        int right = root->right == NULL ? 0 : root->right->val;
        return abs(left - right) <= 1 && helper(root->left) && helper(root->right);
    }
    bool isBalanced(TreeNode* root) {
        getHeight(root);
        return helper(root);
    }
};
// @lc code=end

