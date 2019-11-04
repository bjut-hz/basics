/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    // vector<int> preorderTraversal(TreeNode* root) {
    //     if(NULL == root) return {};

    //     auto left = preorderTraversal(root->left);
    //     auto right = preorderTraversal(root->right);
    //     vector<int> ans;
    //     ans.push_back(root->val);
    //     ans.insert(ans.end(), left.begin(), left.end());
    //     ans.insert(ans.end(), right.begin(), right.end());
    //     return ans;
    // }

    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        if(root) {
            stk.push(root);
        }

        vector<int> ans;
        while(!stk.empty()) {
            auto node = stk.top();
            stk.pop();

            ans.push_back(node->val);
            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left);
        }

        return ans;
    }
};
// @lc code=end

