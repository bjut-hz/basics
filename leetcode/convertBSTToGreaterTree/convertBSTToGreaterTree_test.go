package convertBSTToGreaterTree

import (
	"testing"
	"fmt"
)


func TestConvertBST(t *testing.T) {
	n1 := &TreeNode{Val:5}
	n2 := &TreeNode{Val:2}
	n3 := &TreeNode{Val:13}
	n4 := &TreeNode{Val:4}
	n5 := &TreeNode{Val:11}
	n6 := &TreeNode{Val:15}

	n1.Left = n2
	n1.Right = n3
	n2.Right = n4
	n3.Left = n5
	n3.Right = n6

	fmt.Println(DumpBinaryTree(n1))
	fmt.Println(DumpBinaryTree(convertBST(n1)))
}