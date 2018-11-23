package symmetricTree

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/


type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func isMirror(r1, r2 *TreeNode) bool {
	if r1 == nil && r2 == nil { return true }
	if r1 == nil || r2 == nil { return false }

	return r1.Val == r2.Val && isMirror(r1.Left, r2.Right) && isMirror(r1.Right, r2.Left)
}

func isSymmetric(root *TreeNode) bool {
	if nil == root { return true }
	return isMirror(root.Left, root.Right)
}