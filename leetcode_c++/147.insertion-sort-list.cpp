/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = NULL;

        while(head) {
            ListNode* pre = &dummy;
            while(pre->next != NULL && pre->next->val < head->val) {
                pre = pre->next;
            }

            ListNode* cur = head;
            head = head->next;

            
            cur->next = pre->next;
            pre->next = cur;

        }

        return dummy.next;
    }
};
// @lc code=end

