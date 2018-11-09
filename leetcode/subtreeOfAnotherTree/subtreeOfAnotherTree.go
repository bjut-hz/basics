package subtreeOfAnotherTree

/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a
subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also
be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
*/


type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func isSame(s *TreeNode, t *TreeNode) bool {
	if nil == s {
		return nil == t
	}
	if nil == t {
		return nil == s
	}

	return s.Val == t.Val && isSame(s.Left, t.Left) && isSame(s.Right, t.Right)
}

func isSubtree(s *TreeNode, t *TreeNode) bool {
	if nil == s {
		return nil == t
	}
	if nil == t {
		return nil == s
	}

	return isSame(s, t) || isSubtree(s.Left, t) || isSubtree(s.Right, t)
}