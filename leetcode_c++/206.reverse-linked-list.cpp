/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* new_head = NULL;
    //     while(head) {
    //         ListNode* tmp = head;
    //         head = head->next;

    //         tmp->next = new_head;
    //         new_head = tmp;
    //     }
    //     return new_head;
    // }

    // recusive
    // ListNode* reverseList(ListNode* head) {
    //     if(NULL == head || NULL == head->next) return head;
    //     auto p = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = NULL;
    //     return p;
    // }

    ListNode* reverseList(ListNode* head) {
        if(NULL == head) return NULL;

        ListNode dummy(1);
        dummy.next = head;

        ListNode* pre = &dummy;
        ListNode* last = pre->next;
        ListNode* cur = last->next;
        while(cur != NULL) {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }

        return pre->next;
    }
};
// @lc code=end

