package binaryTreeLevelOrderTraversal

import "container/list"

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/


type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func levelOrder(root *TreeNode) [][]int {
	cache := make(map[*TreeNode]int, 100)
	queue := list.New()
	if root != nil {
		queue.PushBack(root)
		cache[root] = 0
	}

	result := make([][]int, 0, 10)
	for queue.Len() != 0 {
		ele := queue.Front()
		queue.Remove(ele)

		ptr := ele.Value.(*TreeNode)
		if cache[ptr] == len(result) {
			result = append(result, []int{})
		}
		result[cache[ptr]] = append(result[cache[ptr]], ptr.Val)

		if ptr.Left != nil {
			queue.PushBack(ptr.Left)
			cache[ptr.Left] = cache[ptr] + 1
		}

		if ptr.Right != nil {
			queue.PushBack(ptr.Right)
			cache[ptr.Right] = cache[ptr] + 1
		}
	}

	return result
}


func levelOrder1(root *TreeNode) [][]int {
	queue := list.New()
	if root != nil {
		queue.PushBack(root)
	}

	result := make([][]int, 0, 10)
	for queue.Len() != 0 {
		size := queue.Len()

		levelResult := make([]int, 0)
		for i := 0; i < size; i++ {
			ele := queue.Front()
			queue.Remove(ele)

			ptr := ele.Value.(*TreeNode)
			levelResult = append(levelResult, ptr.Val)

			if ptr.Left != nil {
				queue.PushBack(ptr.Left)
			}
			if ptr.Right != nil {
				queue.PushBack(ptr.Right)
			}
		}
		result = append(result, levelResult)
	}

	return result
}

// recursive, use parameter to record the level
func levelHelper(root *TreeNode, result *[][]int, level int ) {
	if root == nil { return }

	if level == len(*result) { *result = append(*result, []int{}) }
	(*result)[level] = append((*result)[level], root.Val)
	levelHelper(root.Left, result, level + 1)
	levelHelper(root.Right, result, level + 1)
}

func levelOrder2(root *TreeNode) [][]int {
	result := make([][]int, 0, 100)
	levelHelper(root, &result, 0)
	return result
}