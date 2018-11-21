package binaryTreeInorderTraversal

/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
*/


type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func inorderTraversal(root *TreeNode) []int {
	if nil == root { return []int{} }

	result := make([]int, 0)
	result = append(result, inorderTraversal(root.Left)...)
	result = append(result, root.Val)
	result = append(result, inorderTraversal(root.Right)...)
	return result
}