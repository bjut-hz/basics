/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (43.79%)
 * Likes:    2148
 * Dislikes: 106
 * Total Accepted:    240.7K
 * Total Submissions: 549.5K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * Example: 
 * 
 * 
 * You may serialize the following tree:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * as "[1,2,3,null,null,4,5]"
 * 
 * 
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
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

// 由于编码信息里包含了null节点信息,因此可以直接通过一种遍历结果就能重建整个树结构

class Codec {
public:
    // // 先序遍历
    // // Encodes a tree to a single string.
    // string serialize(TreeNode* root) {
    //     ostringstream out;
    //     serialize(root, out);

    //     return out.str();
    // }

    // void serialize(TreeNode* root, ostringstream& out) {
    //     if(root) {
    //         out << root->val << ' ';
    //         serialize(root->left, out);
    //         serialize(root->right, out);
    //     } else {
    //         out << "# ";
    //     }
    // }

    // // Decodes your encoded data to tree.
    // TreeNode* deserialize(string data) {
    //     istringstream in(data);
    //     return deserialize(in);
    // }

    // TreeNode* deserialize(istringstream& in) {
    //     string val;
    //     in >> val;
    //     if(val == "#") return NULL;

    //     TreeNode* node = new TreeNode(stoi(val));
    //     node->left = deserialize(in);
    //     node->right = deserialize(in);
    //     return node;
    // }

    // 中序遍历
    string serialize(TreeNode* root) {
        ostringstream out;
        queue<TreeNode*> q;
        if(root) {
            q.push(root);
        }

        while(!q.empty()) {
            TreeNode* ptr = q.front();
            q.pop();

            if(ptr) {
                out << ptr->val << ' ';
                q.push(ptr->left); // 注意这里null节点也会被记录,
                q.push(ptr->right);
            } else {
                out << "# ";
            }
        }

        return out.str();
    }

    // 根据层序遍历结果恢复树结构的写法,借用队列
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        istringstream in(data);
        string val;
        in >> val;
        TreeNode* node = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(node);

        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();

            if(!(in >> val)) {
                break;
            }

            if(val != "#") {
                TreeNode* left = new TreeNode(stoi(val));
                q.push(left);

                t->left = left;
            }

            if(!(in >> val)) {
                break;
            }
            if(val != "#") {
                TreeNode* right = new TreeNode(stoi(val));
                q.push(right);

                t->right = right;
            }
        }

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

