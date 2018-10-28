package invertBinaryTree

import (
	"bytes"
	"fmt"
	"container/list"
)

/*
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
*/



type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func invertTree(root *TreeNode) *TreeNode {
	if nil == root {
		return root
	}

	tmp := root.Right
	root.Right = invertTree(root.Left)
	root.Left = invertTree(tmp)

	return root
}

// level traverse
func DumpBinaryTree(root *TreeNode) string {
	queue := list.New()
	if nil != root {
		queue.PushBack(root)
	}

	var buffer bytes.Buffer
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