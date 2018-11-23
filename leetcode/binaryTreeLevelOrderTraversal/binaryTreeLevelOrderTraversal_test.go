package binaryTreeLevelOrderTraversal

import (
	"testing"
	"fmt"
)



func TestLevelOrder(t *testing.T) {
	n1 := &TreeNode{Val:10}
	n2 := &TreeNode{Val:5}
	n3 := &TreeNode{Val:15}
	n4 := &TreeNode{Val:6}
	n5 := &TreeNode{Val:20}

	n1.Left = n2
	n1.Right = n3
	n3.Left = n4
	n2.Right = n5

	fmt.Println(levelOrder(n1))
	fmt.Println(levelOrder1(n1))
	fmt.Println(levelOrder2(n1))
}