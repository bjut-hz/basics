/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // two pointer
        ListNode* p1 = head;
        ListNode* p2 = head;
        
        for(int i = 0; i < n; ++i) {
            p1 = p1->next;
        }
        
        if(p1 == NULL) return head->next;
        while(p1->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        p2->next = p2->next->next;
        return head;
    }
};
// @lc code=end

