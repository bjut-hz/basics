package binaryTree

import (
	"testing"
	"fmt"
)

func TestTraverse(t *testing.T) {
	n1 := &TreeNode{Val:10}
	n2 := &TreeNode{Val:5}
	n3 := &TreeNode{Val:15}
	n4 := &TreeNode{Val:6}
	n5 := &TreeNode{Val:20}

	n1.Left = n2
	n1.Right = n3
	n3.Left = n4
	n2.Right = n5

	/*
	            10
			/		\
	       5		 15
	        \	    /
	        20     6
	*/
	fmt.Println("------ traverse recusively -----")
	fmt.Println(preOrderTraverse(n1))
	fmt.Println(inOrderTraverse(n1))
	fmt.Println(postOrderTraverse(n1))

	fmt.Println("------ traverse iteratively -----")
	fmt.Println(preOrder(n1))
	fmt.Println(inOrder(n1))
	fmt.Println(postOrder(n1))

	fmt.Println("------ morris iteratively -----")
	fmt.Println(morrisPreOrder(n1))
	fmt.Println(morrisInOrder(n1))
	fmt.Println(morrisPostOrder(n1))
}