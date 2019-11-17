/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* helper(Node* node, map<Node*, Node*>& visited) {
        if(NULL == node) return NULL;
        if(visited.count(node)) return visited[node];
        
        Node* ptr = new Node(node->val, NULL, NULL);
        visited[node] = ptr;
        ptr->next = helper(node->next, visited);
        ptr->random = helper(node->random, visited);
        return ptr;
    } 
    
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> visited;
        return helper(head, visited);
    }
};
// @lc code=end

