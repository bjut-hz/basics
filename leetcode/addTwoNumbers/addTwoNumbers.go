package addTwoNumbers

import (
	"strings"
	"fmt"
)

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order
and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/



type ListNode struct {
    Val int
    Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	result := &ListNode{Val:0}
	ptr := result
	carry := 0
	for l1 != nil && l2 != nil {
		ptr.Next = l1
		ptr.Next.Val = l1.Val + l2.Val + carry
		carry = ptr.Next.Val / 10
		ptr.Next.Val %= 10

		l1 = l1.Next
		l2 = l2.Next
		ptr = ptr.Next
	}

	for nil != l1 {
		ptr.Next = l1
		ptr.Next.Val = l1.Val  + carry
		carry = ptr.Next.Val / 10
		ptr.Next.Val %= 10

		l1 = l1.Next
		ptr = ptr.Next
	}

	for nil != l2 {
		ptr.Next = l2

		ptr.Next.Val = l2.Val + carry
		carry = ptr.Next.Val / 10
		ptr.Next.Val %= 10

		l2 = l2.Next
		ptr = ptr.Next
	}

	if 0 != carry {
		node := &ListNode{Val:carry}
		ptr.Next = node
	}
	return result.Next
}


func DumpList(head *ListNode) string {
	var buffer strings.Builder
	for ; head != nil; head = head.Next {
		buffer.WriteString(fmt.Sprintf("%v ", head.Val))
	}
	return buffer.String()
}