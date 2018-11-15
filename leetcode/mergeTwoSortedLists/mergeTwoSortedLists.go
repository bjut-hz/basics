package mergeTwoSortedLists

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/


type ListNode struct {
    Val int
    Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	if nil == l1 {
		return l2
	}
	if nil == l2 {
		return l1
	}

	var result *ListNode
	if l1.Val > l2.Val {
		result = l2
		result.Next = mergeTwoLists(l1, l2.Next)
	} else {
		result = l1
		result.Next = mergeTwoLists(l1.Next, l2)
	}
	return result
}