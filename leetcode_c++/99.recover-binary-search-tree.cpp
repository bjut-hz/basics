/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    // void inoder(TreeNode* root, vector<TreeNode*>& nodes, vector<int>& res) {
    //     if(NULL == root) return;

    //     inoder(root->left, nodes, res);
    //     nodes.push_back(root);
    //     res.push_back(root->val);
    //     inoder(root->right, nodes, res);
    // }
    // void recoverTree(TreeNode* root) {
    //     vector<TreeNode*> nodes;
    //     vector<int> res;

    //     inoder(root, nodes, res);
    //     sort(res.begin(), res.end());
    //     for(int i = 0; i < nodes.size(); ++i){
    //         nodes[i]->val = res[i];
    //     }
    // }
    TreeNode* pre = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;

    void inoder(TreeNode* root) {
        if(NULL == root) return;
        inoder(root->left);

        if(pre == NULL) {
            pre = root;
        } else {
            if(pre->val > root->val) {
                if(NULL == first) {
                    first = pre;
                }
                second = root;
            }
            pre = root;
        }
        inoder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inoder(root);
        swap(first->val, second->val);
    }
};
// @lc code=end

