package removeNthNodeFromEndOfList

/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/



type ListNode struct {
    Val int
    Next *ListNode
}

// usr two pointers
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if nil == head {
		return head
	}
	pre := head
	pioneer := head

	for i := 0; i <= n; i++ {
		if pioneer == nil {
			return head.Next
		}
		pioneer = pioneer.Next
	}

	for nil != pioneer {
		pioneer = pioneer.Next
		pre = pre.Next
	}
	pre.Next = pre.Next.Next
	return head
}