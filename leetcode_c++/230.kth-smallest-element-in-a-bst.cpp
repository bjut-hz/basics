/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    // int kthSmallest(TreeNode* root, int k) {
    //     int cnt = 0;
    //     int res = 0;
    //     inoder(root, cnt, res, k);
    //     return res;
    // }

    // void inoder(TreeNode* root, int& cnt, int& res, int target) {
    //     if(NULL == root) return;
    //     inoder(root->left, cnt, res, target);
    //     ++cnt;
    //     if(cnt == target) {
    //         res = root->val;
    //         return;
    //     }
    //     inoder(root->right, cnt, res, target);
    // }


    // divide and conquer
    int kthSmallest(TreeNode* root, int k) {
        int left_cnt = count(root->left);
        if(k <= left_cnt) {
            return kthSmallest(root->left, k);
        } else if(k > left_cnt + 1) {
            return kthSmallest(root->right, k - left_cnt - 1);
        }
        return root->val;
    }

    int count(TreeNode* root) {
        if(NULL == root) return 0;
        return 1 + count(root->left) + count(root->right);
    }
};
// @lc code=end

