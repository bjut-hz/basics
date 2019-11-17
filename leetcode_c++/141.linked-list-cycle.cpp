/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(NULL == head) return false;

        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }

        return false;
    }
};
// @lc code=end

