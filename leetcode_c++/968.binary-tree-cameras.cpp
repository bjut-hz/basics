/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
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
/*
我们在处理该问题过程中，每个二叉树节点的状态可能有以下三种：

状态0：节点没有被监控
状态1：节点被监控了但是节点上并没有摄像头
状态2：节点被监控了同时节点上安装了摄像头
我们自底向上地解决此问题，在解决过程中，先保证每个节点的所有子节点全被监控，再返回到父节点。比起把摄像头安装在0状态节点，更好地做法是把摄像头安装在0状态节点的父节点，后者监控的节点数量一定大于等于前者。显然，我们首先遇到的0状态节点就是最底层的叶节点。

对于一个节点，我们首先递归得到左子节点状态 left 和右子节点的状态 right。若 left 等于0或 right 等于0，说明该节点一定要安装摄像头，摄像头数量 +1 后，向上返回 2；否则， 若 left 和 right 都等于1，说明该节点在状态0，我们只需把摄像头装在它的父节点，向上返回 0即可；否则，说明子节点中存在摄像头，该节点已经被监控，我们向上返回 1。

最后，要注意若根节点在0状态，最终的摄像头数量需要 +1。
*/
class Solution {
public:
    int bottomUp(TreeNode* root, int& res) {
        if(NULL == root) return 1;
        int left = bottomUp(root->left, res);
        int right = bottomUp(root->right, res);

        if(left == 0 || right == 0) {
            res += 1;
            return 2;
        } else if(left == 1 && right == 1) {
            return 0;
        } else {
            return 1;
        }
    }
    int minCameraCover(TreeNode* root) {
        int res = 0;
        if(bottomUp(root, res) == 0) {
            res++;
        }
        return res;
    }
};
// @lc code=end

