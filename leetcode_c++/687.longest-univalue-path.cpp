/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
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
    // 递归表示以当前节点为终点的最大单侧路径长度
    int helper(TreeNode* root, int parent, int& res) {
        if(NULL == root) return 0;

        int left = helper(root->left, root->val, res);
        int right = helper(root->right, root->val, res);

        res = max(res, left + right);
        if(root->val == parent) {
            return max(left, right) + 1;
        }
        return 0;
    }

    int longestUnivaluePath(TreeNode* root) {
        if(NULL == root) return 0;
        int res = 0;
        helper(root, root->val, res);
        return res;
    }
    // int helper(TreeNode* root, int parent) {
    //     if(NULL == root) return 0;

    //     if(root->val == parent) {
    //         return 1 + max(helper(root->left, parent), helper(root->right, parent));
    //     } else {
    //         return 0;
    //     }
    // }
    // int longestUnivaluePath(TreeNode* root) {
    //     if(root == NULL) return 0;
    //     int left = longestUnivaluePath(root->left); // 左子树的最长路径
    //     int right = longestUnivaluePath(root->right);
    //     int max_child = max(left, right);
    //     return max(max_child, helper(root->left, root->val) + helper(root->right, root->val));
    // }
};
// @lc code=end

