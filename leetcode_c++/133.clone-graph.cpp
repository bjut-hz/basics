/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* helper(Node* node, map<Node*, Node*>& visited) {
        if(visited.count(node)) return visited[node];

        Node* ptr = new Node(node->val);
        visited[node] = ptr;
        for(Node* n : node->neighbors) {
            ptr->neighbors.push_back(helper(n, visited));
        }

        return ptr;
    }
    Node* cloneGraph(Node* node) {
        if(NULL == node) return NULL;
        map<Node*, Node*> visited;
        return helper(node, visited);   
    }
};
// @lc code=end

