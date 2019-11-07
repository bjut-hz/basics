/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    // vector<int> inorderTraverse(TreeNode* root) {
    //     if(NULL == root) return {};

    //     auto left = inorderTraverse(root->left);
    //     auto right = inorderTraverse(root->right);

    //     vector<int> ans;
    //     ans.insert(ans.end(), left.begin(), left.end());
    //     ans.push_back(root->val);
    //     ans.insert(ans.end(), right.begin(), right.end());
    //     return ans;
    // }
    // bool isValidBST(TreeNode* root) {
    //     auto nums = inorderTraverse(root);

    //     for(int i = 0; i < int(nums.size()) - 1; ++i) {
    //         if(nums[i] >= nums[i+1]){
    //             return false;
    //         }
    //     }

    //     return true;
    // }

    bool isValidBST(TreeNode* root, long long min, long long max) {
        if(NULL == root) return true;
        if(root->val <= min || root->val >= max) {return false;}
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};
// @lc code=end

