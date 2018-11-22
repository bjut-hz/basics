package validateBinarySearchTree

import "math"

/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
    2
   / \
  1   3
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
*/


type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

// inorder traverse
func traverse(root *TreeNode) []int {
	if nil == root { return []int{} }

	result := make([]int, 0)
	result = append(result, traverse(root.Left)...)
	result = append(result, root.Val)
	result = append(result, traverse(root.Right)...)
	return result
}

func isValidBST(root *TreeNode) bool {
	nums := traverse(root)
	for i := 0; i < len(nums) - 1; i++ {
		if nums[i] >= nums[i+1] {
			return false
		}
	}
	return true
}


func recursive(root *TreeNode, max int64, min int64) bool {
	if nil == root { return true }
	if int64(root.Val) >= max || int64(root.Val) <= min { return false }

	return recursive(root.Left, int64(root.Val), min) && recursive(root.Right, max, int64(root.Val))
}

func isValidBST1(root *TreeNode) bool {
	return recursive(root, math.MaxInt64, math.MinInt64)
}