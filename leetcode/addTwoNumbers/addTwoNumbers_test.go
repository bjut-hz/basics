package addTwoNumbers


import (
	"testing"
	"fmt"
)


func TestAddTwoNumbers(t *testing.T) {
	l1 := &ListNode{Val:2}
	l2 := &ListNode{Val:8}
	fmt.Println(DumpList(addTwoNumbers(l1, l2)))
}