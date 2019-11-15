/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    // non recursive, use queue
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     vector<vector<int>> res;
    //     queue<TreeNode*> q;
    //     if(root) q.push(root);

    //     while(!q.empty()) {
    //         int n = q.size();
    //         vector<int> tmp;
    //         for(int i = 0; i < n; ++i) {
    //             TreeNode* ptr = q.front();
    //             tmp.push_back(ptr->val);
    //             q.pop();

    //             if(ptr->left) q.push(ptr->left);
    //             if(ptr->right) q.push(ptr->right);
    //         }

    //         res.push_back(tmp);
    //     }

    //     return res;
    // }

    // recursive
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelTraverse(res, root, 0);
        return res;
    }

    void levelTraverse(vector<vector<int>>& res, TreeNode* node, int level) {
        if(NULL == node) return;

        // 关键
        if(res.size() == level) {
            res.push_back({});
        }
        res[level].push_back(node->val);

        if(node->left) {
            levelTraverse(res, node->left, level + 1);
        }

        if(node->right) {
            levelTraverse(res, node->right, level + 1);
        }
    }
};
// @lc code=end

