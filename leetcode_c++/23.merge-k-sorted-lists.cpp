/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        return mergeKLists(lists, 0, lists.size() - 1);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists, int l, int r) {
        if(l >= r) return lists[l];

        int mid = l + (r - l) / 2;
        ListNode* l_list = mergeKLists(lists, l, mid);
        ListNode* r_list = mergeKLists(lists, mid + 1, r);
        return mergeTwoLists(l_list, r_list);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode* result = NULL;
        if(l1->val < l2->val) {
            result = l1;
            result->next = mergeTwoLists(l1->next, l2);
        } else {
            result = l2;
            result->next = mergeTwoLists(l1, l2->next);
        }
        return result;
    }
};
// @lc code=end

