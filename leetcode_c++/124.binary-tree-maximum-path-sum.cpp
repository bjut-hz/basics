/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return INT_MIN;
        int left = 0;
        getRootMaxSum(root->left, 0, left);
        int right = 0;
        getRootMaxSum(root->right, 0, right);


        return max(root->val + left + right, max(maxPathSum(root->left), maxPathSum(root->right)));
    }

    void getRootMaxSum(TreeNode* root, int sum, int& res) {
        if(sum > res) {
            res = sum;
        }

        if(NULL == root) return;
        getRootMaxSum(root->left, root->val + sum, res);
        getRootMaxSum(root->right, root->val + sum, res);
    }
};
// @lc code=end

