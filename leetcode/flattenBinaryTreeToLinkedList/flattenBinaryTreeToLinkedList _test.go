package flattenBinaryTreeToLinkedList

import (
	"testing"
)

func TestFlatten(t *testing.T) {
	n1 := &TreeNode{Val:1}
	n2 := &TreeNode{Val:2}
	n3 := &TreeNode{Val:3}
	n4 := &TreeNode{Val:4}
	//n5:= &TreeNode{Val:5}
	//n6 := &TreeNode{Val:6}

	n1.Left = n2
	n1.Right = n3
	n2.Left = n4

	flatten(n1)
}