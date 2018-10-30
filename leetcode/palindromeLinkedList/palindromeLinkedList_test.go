package palindromeLinkedList

import (
	"testing"
	"fmt"
)

func TestPalindromeLinkedList(t *testing.T)  {
	l1 := &ListNode{Val:1}
	l2 := &ListNode{Val:2}
	l3 := &ListNode{Val:2}
	l4 := &ListNode{Val:1}

	l1.Next = l2
	l2.Next = l3
	l3.Next = l4
	//l4.Next = nil

	fmt.Println(isPalindrome(l1))
}