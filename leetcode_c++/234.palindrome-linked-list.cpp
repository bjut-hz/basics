/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        if(NULL == head || NULL == head->next) return true;

        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* last = slow->next;
        ListNode* cur = last->next;
        // reverse list
        while(cur) {
            last->next = cur->next;
            cur->next = slow->next;
            slow->next = cur;
            cur = last->next;
        }

        ListNode* ptr = slow->next;
        while(ptr) {
            if(ptr->val != head->val) {
                return false;
            }
            head = head->next;
            ptr = ptr->next;
        }

        return true;
    }
};
// @lc code=end

