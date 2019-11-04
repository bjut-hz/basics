/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode* ans = NULL;
        if(l1->val < l2->val) {
            ans = l1;
            ans->next = mergeTwoLists(l1->next, l2);
        } else {
            ans = l2;
            ans->next = mergeTwoLists(l1, l2->next);
        }
        
        return ans;
    }
};
// @lc code=end

