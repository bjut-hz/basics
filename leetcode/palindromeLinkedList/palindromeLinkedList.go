package palindromeLinkedList

/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
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
			return slow.Next
		}
	}
}

// use a pointer to reverse half part of the linked list
func isPalindrome(head *ListNode) bool {
	if nil == head || nil == head.Next {
		return true
	}

	middle := getMiddle(head)
	ptr := &ListNode{Next:nil} // dummy node
	// reverse the linked list
	for nil != middle {
		tmp := middle
		middle = middle.Next

		tmp.Next = ptr.Next
		ptr.Next = tmp
	}

	ptr = ptr.Next
	for nil != ptr {
		if ptr.Val != head.Val {
			return false
		}
		ptr = ptr.Next
		head = head.Next
	}

	return true
}