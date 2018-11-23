package constructBinaryTreeFromPreorderAndInorderTraversal

/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/


type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	if 0 == len(preorder) { return nil }

	root := &TreeNode{Val:preorder[0]}
	idx := 0
	for i := 0; i < len(inorder); i++ {
		if inorder[i] == preorder[0] {
			idx = i
			break
		}
	}

	root.Left = buildTree(preorder[1: 1 + idx], inorder[0:idx+1])
	root.Right = buildTree(preorder[1 + idx:], inorder[idx+1:])

	return root
}