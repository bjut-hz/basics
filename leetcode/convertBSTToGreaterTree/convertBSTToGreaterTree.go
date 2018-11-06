package convertBSTToGreaterTree

import (
	"bytes"
	"fmt"
	"container/list"
)

/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the
original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
*/


type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func convertBST(root *TreeNode) *TreeNode {
	if nil == root {
		return root
	}
	sum := 0
	converter(root, &sum)
	return root
}

func converter(root *TreeNode, sum *int) *TreeNode {
	if nil == root {
		return nil
	}

	converter(root.Right, sum)
	*sum += root.Val
	root.Val = *sum
	converter(root.Left, sum)
	return root
}

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