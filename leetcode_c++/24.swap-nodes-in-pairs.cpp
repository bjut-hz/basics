/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (47.28%)
 * Likes:    1573
 * Dislikes: 137
 * Total Accepted:    382.1K
 * Total Submissions: 807.5K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * 
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
    // ListNode* swapPairs(ListNode* head) {
    //     if(nullptr == head || nullptr == head->next) return head;

    //     ListNode dummy(0);
    //     dummy.next = head;

    //     ListNode* pre = &dummy;
    //     ListNode* pos = head;
    //     ListNode* next = pos->next;

    //     while(true) {
    //         pos->next = next->next;
    //         next->next = pos;
    //         pre->next = next;

    //         if(pos->next && pos->next->next) {
    //             pre = pos;
    //             pos = pos->next;
    //             next = pos->next;
    //         } else {
    //             break;
    //         }
    //     }

    //     return dummy.next;
    // }


    // swap value
    ListNode* swapPairs(ListNode* head) {
        if(nullptr == head || nullptr == head->next) return head;

        ListNode* ptr = head;
        while(ptr && ptr->next) {
            swap(ptr->val, ptr->next->val);
            ptr = ptr->next->next;
        }
        return head;
    }
};
// @lc code=end

