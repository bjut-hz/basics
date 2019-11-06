/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(NULL == l1) return l2;
        if(NULL == l2) return l1;

        ListNode* ans;
        if(l1->val < l2->val) {
            ans = l1;
            ans->next = merge(l1->next, l2);
        } else {
            ans = l2;
            ans->next = merge(l1, l2->next);
        }
        return ans;
    }

    ListNode* sortList(ListNode* head) {
        if(NULL == head || head->next == NULL) return head;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = head;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        auto left = sortList(head);
        auto right = sortList(slow);

        return merge(left, right);
    }
};
// @lc code=end

