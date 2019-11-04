/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    // vector<int> inorderTraversal(TreeNode* root) {
    //     if(NULL == root) return {};
    //     vector<int> ans;

    //     auto left = inorderTraversal(root->left);
    //     auto right = inorderTraversal(root->right);
    //     ans.insert(ans.end(), left.begin(), left.end());
    //     ans.insert(ans.end(), root->val);
    //     ans.insert(ans.end(), right.begin(), right.end());

    //     return ans;
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        auto ptr = root;
        vector<int> ans;
        while(NULL != ptr || !stk.empty()) {
            if(NULL == ptr) {
                auto node = stk.top();
                stk.pop();
                
                ans.push_back(node->val); // 左子树访问完后，访问该节点
                ptr = node->right;
            } else {
                stk.push(ptr);
                ptr = ptr->left;
            }
        }

        return ans;
    }
};
// @lc code=end

