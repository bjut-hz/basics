package mergeTwoBinaryTrees

import (
	"fmt"
	"container/list"
	"strings"
)

/*
Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:

Input:
	Tree 1                     Tree 2
          1                         2
         / \                       / \
        3   2                     1   3
       /                           \   \
      5                             4   7
Output:
Merged tree:
	     3
	    / \
	   4   5
	  / \   \
	 5   4   7


Note: The merging process must start from the root nodes of both trees.
*/


type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func mergeTrees(t1 *TreeNode, t2 *TreeNode) *TreeNode {
	if nil == t1 {
		return t2
	}
	if nil == t2 {
		return t1
	}

	result := t1
	result.Val = t1.Val + t2.Val
	result.Left = mergeTrees(t1.Left, t2.Left)
	result.Right = mergeTrees(t1.Right, t2.Right)

	return result
}

// level traverse
func DumpBinaryTree(root *TreeNode) string {
	queue := list.New()
	if nil != root {
		queue.PushBack(root)
	}

	var buffer strings.Builder
	for 0 != queue.Len() {
		// dequeue
		element := queue.Front()
		queue.Remove(element)
		node := element.Value.(*TreeNode)
		buffer.WriteString(fmt.Sprintf("%v, ", node.Val))

		// enqueue
		if nil != node.Left {
			queue.PushBack(node.Left)
		}
		if nil != node.Right {
			queue.PushBack(node.Right)
		}
	}

	return buffer.String()
}