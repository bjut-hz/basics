package mergeKSortedLists

/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
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


func mergeKLists(lists []*ListNode) *ListNode {
	L := len(lists)
	if 0 == L {
		return nil
	}
	if 1 == L {
		return lists[0]
	}

	mid := L / 2
	return mergeTwoLists(mergeKLists(lists[0:mid]), mergeKLists(lists[mid:]))
}