package maximumDepthOfBinaryTree

/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
*/


type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func max2(a, b int) int {
	if a > b { return a }
	return b
}

func maxDepth(root *TreeNode) int {
	if nil == root {return 0}

	return 1 + max2(maxDepth(root.Left), maxDepth(root.Right))
}