/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumber(ListNode* l1, ListNode* l2, int carry = 0) {
        if(NULL == l1 && NULL == l2) {
            if(carry != 0) {
                return new ListNode(1);
            } else {
                return NULL;
            }
        }
        if(NULL == l1) {
            if(carry != 0) {
                return addTwoNumber(new ListNode(1), l2, 0);
            } else {
                return l2;
            }
        }
        
        if(l2 == NULL) return addTwoNumber(l2, l1, carry);
        
        ListNode* ans = l1;
        int sum = l1->val + l2->val + carry;
        ans->val = sum % 10;
        carry = sum / 10;
        
        ans->next = addTwoNumber(l1->next, l2->next, carry);
        return ans;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumber(l1, l2, 0);
    }
};
// @lc code=end

