package binaryTreeMaximumPathSum

import (
	"math"
)

/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the
parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/


type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

var cache = make(map[*TreeNode]int, 10)

func max2(a, b int) int {
	if a > b { return a }
	return b
}

func max3(a, b, c int) int {
	return max2(a, max2(b, c))
}

func maxRootPathSum(root *TreeNode) int {
	if nil == root { return 0 }

	if _, ok := cache[root]; !ok {
		cache[root] = max3(root.Val, root.Val + maxRootPathSum(root.Left), root.Val + maxRootPathSum(root.Right))
	}

	return cache[root]
}

func maxPathSum(root *TreeNode) int {
	if nil == root { return 0 }
	if nil == root.Left && nil == root.Right { return root.Val }

	leftPathSum := math.MinInt32
	rightPathSum := math.MinInt32
	if nil != root.Left {
		leftPathSum = maxPathSum(root.Left)
	}
	if nil != root.Right {
		rightPathSum = maxPathSum(root.Right)
	}

	return max2(max3(root.Val, root.Val + maxRootPathSum(root.Left), root.Val + maxRootPathSum(root.Right)),
		max3(root.Val + maxRootPathSum(root.Left) + maxRootPathSum(root.Right), leftPathSum, rightPathSum))
}




// only run once for every tree node, so does not need cache
func maxRootPath(root *TreeNode, result *int) int {
	if nil == root { return 0 }
	left := max2(maxRootPath(root.Left, result), 0) // amazing skill, compare with 0 so that we can ignore negative num
	right := max2(maxRootPath(root.Right, result), 0)

	*result = max2(*result, root.Val + left + right)

	return max2(root.Val + left, root.Val + right)
}

func maxPathSum1(root *TreeNode) int {
	res := math.MinInt32
	maxRootPath(root, &res)
	return res
}