package sortList

import (
	"testing"
	"fmt"
)

func TestGetMiddle(t *testing.T)  {
	l1 := &ListNode{Val:1}
	l2 := &ListNode{Val:2}
	l3 := &ListNode{Val:3}
	l4 := &ListNode{Val:4}

	l1.Next = l2
	l2.Next = l3
	l3.Next = l4
	//l4.Next = nil

	node := getMiddle(l1)
	fmt.Println(node.Val)
}



func TestMerge(t *testing.T)  {
	l1 := &ListNode{Val:1, Next:nil}
	l2 := &ListNode{Val:10, Next:nil}
	l3 := &ListNode{Val:20, Next:nil}
	l4 := &ListNode{Val:400, Next:nil}

	l1.Next = l2
	l2.Next = l3
	l3.Next = l4

	n1 := &ListNode{Val:2, Next:nil}
	n2 := &ListNode{Val:5, Next:nil}
	n3 := &ListNode{Val:60, Next:nil}
	n1.Next = n2
	n2.Next = n3

	ret := merge(l1, n1)
	fmt.Println(DumpList(ret))
}

func TestSortList(t *testing.T)  {
	l1 := &ListNode{Val:100, Next:nil}
	l2 := &ListNode{Val:10, Next:nil}
	//l3 := &ListNode{Val:20, Next:nil}
	//l4 := &ListNode{Val:400, Next:nil}

	l1.Next = l2
	//l2.Next = l3
	//l3.Next = l4

	fmt.Println(DumpList(sortList(l1)))
}