/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk1, stk2;

        if(root) {
            stk1.push(root);
        }

        while(!stk1.empty()) {
            auto node = stk1.top();
            stk1.pop();

            stk2.push(node);

            if(node->left) stk1.push(node->left);
            if(node->right) stk1.push(node->right);
        }

        vector<int> ans;
        while(!stk2.empty()) {
            auto node = stk2.top();
            stk2.pop();
            ans.push_back(node->val);
        }

        return ans;
    }
};
// @lc code=end

