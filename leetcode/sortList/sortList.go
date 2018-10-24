package sortList

import (
	"bytes"
	"fmt"
)

/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/

type ListNode struct {
    Val int
    Next *ListNode
}

func getMiddle(head *ListNode) *ListNode {
	if nil == head {
		return head
	}

	fast, slow := head, head
	for {
		if slow.Next != nil && fast.Next != nil && fast.Next.Next != nil {
			slow = slow.Next
			fast = fast.Next.Next
		} else {
			return slow
		}
	}
}

func merge(l1, l2 *ListNode) *ListNode {
	result := &ListNode{Next:nil, Val:0} // dummy node
	tail := result
	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			tail.Next = l1
			l1 = l1.Next
		} else {
			tail.Next = l2
			l2 = l2.Next
		}
		tail = tail.Next
	}

	for ; l1 != nil; l1 = l1.Next {
		tail.Next = l1
		tail = tail.Next
	}

	for ; l2 != nil; l2 = l2.Next {
		tail.Next = l2
		tail = tail.Next
	}

	return result.Next
}

func sortList(head *ListNode) *ListNode {
	if nil == head || nil == head.Next {
		return head
	}

	center := getMiddle(head)
	right := center.Next
	center.Next = nil
	return merge(sortList(head), sortList(right))
}

func DumpList(head *ListNode) string {
	var buffer bytes.Buffer
	for ; head != nil; head = head.Next {
		buffer.WriteString(fmt.Sprintf("%v ", head.Val))
	}
	return buffer.String()
}