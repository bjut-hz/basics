package reverseLinkedList

import (
	"bytes"
	"fmt"
)

/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

type ListNode struct {
	Val int
	Next *ListNode
}

// iteration
func reverseListIteratively(head *ListNode) *ListNode {
	result := &ListNode{Val:-1, Next:nil} // dummy node

	for ptr := head; nil != ptr; {
		tmp := ptr
		ptr = ptr.Next

		tmp.Next = result.Next
		result.Next = tmp
	}

	return result.Next
}

// recursive
func reverseListRecursively(head *ListNode) *ListNode {
	if nil == head || nil == head.Next {
		return head
	}

	result := reverseListRecursively(head.Next)
	head.Next.Next = head
	head.Next = nil

	return result
}

func DumpList(head *ListNode) string {
	var buffer bytes.Buffer
	for ; head != nil; head = head.Next {
		buffer.WriteString(fmt.Sprintf("%v ", head.Val))
	}
	return buffer.String()
}