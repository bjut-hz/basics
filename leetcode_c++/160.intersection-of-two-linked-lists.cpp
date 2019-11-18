/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    // int getLen(ListNode* head) {
    //     if(NULL == head) return 0;

    //     return 1 + getLen(head->next);
    // }

    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //       int l1 = getLen(headA);
    //       int l2 = getLen(headB);

    //       if(l1 < l2) {
    //           for(int i = 0; i < l2 - l1; ++i) {
    //               headB = headB->next;
    //           }
    //       }

    //       if(l1 > l2) {
    //           for(int i = 0; i < l1 - l2; ++i) {
    //               headA = headA->next;
    //           }
    //       }

    //       while(headA != headB) {
    //           headA = headA->next;
    //           headB = headB->next;
    //       }  

    //       return headA;
    // }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(NULL == headA || NULL == headB) return NULL;

        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        while(ptr1 != ptr2) {
            // 编程总结:我们使用一个指针一般只需要判断该指针是否为空
            ptr1 = ptr1 ? ptr1->next : headB; // 注意在这里要判断ptr为NULL而不是ptr->next,否则如果没有相交的话会陷入死循环，因为一直会重头开始了！！
            ptr2 = ptr2 ? ptr2->next : headA;
        }

        return ptr1;
    }
};
// @lc code=end

