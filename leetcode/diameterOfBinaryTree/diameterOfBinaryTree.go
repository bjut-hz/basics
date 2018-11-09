package diameterOfBinaryTree

/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/


type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

// cache height
var cache = make(map[*TreeNode]int, 10)

func max2(a, b int) int {
	if a > b { return a }
	return b
}


func max3(a, b, c int) int {
	return max2(max2(a, b), c)
}

func height(root *TreeNode) int {
	if nil == root {
		return 0
	}

	if _, ok := cache[root]; !ok {
		cache[root] = 1 + max2(height(root.Left), height(root.Right))
	}
	return cache[root]
}

func diameterOfBinaryTree(root *TreeNode) int {
	if nil == root {
		return 0
	}
	return max3(height(root.Left) + height(root.Right), diameterOfBinaryTree(root.Left), diameterOfBinaryTree(root.Right))
}
