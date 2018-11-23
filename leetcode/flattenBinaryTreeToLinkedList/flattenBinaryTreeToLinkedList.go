package flattenBinaryTreeToLinkedList

/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/


type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func flatten(root *TreeNode)  {
	if nil == root { return }

	flatten(root.Left)
	flatten(root.Right)

	if nil != root.Left {
		tmp := root.Right
		root.Right = root.Left

		ptr := root.Left
		for ;ptr.Right != nil; ptr = ptr.Right {}
		ptr.Right = tmp

		root.Left = nil
	}
}