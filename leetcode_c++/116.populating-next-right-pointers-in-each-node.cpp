/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    // level traverse
    // Node* connect(Node* root) {
    //     queue<Node*> q;
    //     if(root) q.push(root);

    //     while(!q.empty()) {
    //         int n = q.size();
    //         for(int i = 0; i < n; ++i) {
    //             auto ptr = q.front();
    //             q.pop();

    //             if(i == n - 1) {
    //                 ptr->next = NULL;
    //             } else {
    //                 ptr->next = q.front();
    //             }

    //             if(ptr->left) {
    //                 q.push(ptr->left);
    //             }
    //             if(ptr->right) {
    //                 q.push(ptr->right);
    //             }
    //         }
    //     }

    //     return root;
    // }

    Node* connect(Node* root) {
        if(NULL == root) return NULL;

        if(root->left) {
            root->left->next = root->right;
        }

        if(root->right) {
            root->right->next = root->next == NULL ? NULL : root->next->left;
        }

        connect(root->left);
        connect(root->right);

        return root;
    }
};
// @lc code=end

