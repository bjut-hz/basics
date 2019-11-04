/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(NULL == root) return {};
        int cnt = 0;
        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> ans;
        while(!q.empty()) {
            vector<int> res;
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                res.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(cnt % 2 == 1) {
                reverse(res.begin(), res.end());
            }

            ans.push_back(res);
            ++cnt;
        }

        return ans;
    }
};
// @lc code=end

