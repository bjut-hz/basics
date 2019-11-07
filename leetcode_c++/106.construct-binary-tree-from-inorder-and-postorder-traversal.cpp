/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int in_l, int in_r, int pos_l, int pos_r) {
        if(pos_l > pos_r) return NULL;

        TreeNode* node = new TreeNode(postorder[pos_r]);
        int pos = in_l;
        for(; pos <= in_r; ++pos) {
            if(inorder[pos] == postorder[pos_r]) {
                break;
            }
        }
        int num = pos - in_l;
        node->left = buildTree(inorder, postorder, in_l, pos - 1, pos_l, pos_l + num - 1);
        node->right = buildTree(inorder, postorder, pos + 1, in_r, pos_l + num, pos_r - 1);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, 0, int(inorder.size()) - 1, 0, int(postorder.size()) - 1);
    }
};
// @lc code=end

