/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pre_l, int pre_r, int in_l, int in_r) {
        if(pre_l > pre_r) return NULL;

        TreeNode* node = new TreeNode(preorder[pre_l]);

        int pos = in_l;
        for(; pos <= pre_r; ++pos) {
            if(inorder[pos] == preorder[pre_l]) {
                break;
            }
        }
        int num = pos - in_l;
        node->left = buildTree(preorder, inorder, pre_l + 1, pre_l + num, in_l, pos - 1);
        node->right = buildTree(preorder, inorder, pre_l + num + 1, pre_r,  pos + 1, in_r);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, int(preorder.size()) - 1, 0, int(inorder.size()) - 1);
    }
};
// @lc code=end

