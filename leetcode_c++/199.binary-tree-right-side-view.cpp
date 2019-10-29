/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        if(NULL == root) return {};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            ans.push_back(q.back()->val);

            int size = q.size();
            for(int i = 0; i < size; ++i) { // 注意这里，直接把同一层的元素都弹出，那么队列里剩的就全是同一个层级的
                TreeNode* node = q.front();
                q.pop();

                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

