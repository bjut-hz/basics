/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (47.87%)
 * Likes:    1870
 * Dislikes: 114
 * Total Accepted:    181K
 * Total Submissions: 378.2K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root.
 * 
 * 
 * 
 * Example:
 * Given a binary tree 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \     
 * ⁠     4   5    
 * 
 * 
 * 
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 * 
 * 
 * Note:
 * The length of path between two nodes is represented by the number of edges
 * between them.
 * 
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
    map<TreeNode*, int> h_;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        helper(root, res);

        return res;
    }

    int helper(TreeNode* root, int & res) {
        if(nullptr == root) return 0;
        if(h_.count(root)) return h_[root];
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        res = max(res, left + right);
        h_[root] = 1 + max(left, right);
        return h_[root];
    }
};
// @lc code=end

