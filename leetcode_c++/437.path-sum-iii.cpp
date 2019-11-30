/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (44.26%)
 * Likes:    2419
 * Dislikes: 157
 * Total Accepted:    135.8K
 * Total Submissions: 306.8K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * You are given a binary tree in which each node contains an integer value.
 * 
 * Find the number of paths that sum to a given value.
 * 
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards
 * (traveling only from parent nodes to child nodes).
 * 
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 * 
 * Example:
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * Return 3. The paths that sum to 8 are:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
 * 
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
public:
    int pathSum(TreeNode* root, int sum) {
        if(nullptr == root) return 0;
        return pathFromNode(root, root->val, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int pathFromNode(TreeNode* node, int sum_now, int target) {
        if(nullptr == node) {return 0;}

        int cnt = 0;
        if(sum_now == target) {
            cnt = 1; // 注意要使用cnt来统计,因为从一个节点可能有多个路径
        }

        if(node->left) {
            cnt += pathFromNode(node->left, node->left->val + sum_now, target);
        }
        if(node->right) {
            cnt += pathFromNode(node->right, sum_now + node->right->val, target);
        }

        return cnt;
    }
};
// @lc code=end

