package mergeTwoBinaryTrees

import (
	"testing"
	"fmt"
)

func TestMergeTrees(t *testing.T) {
	n1 := &TreeNode{Val:1}
	n2 := &TreeNode{Val:3}
	n3 := &TreeNode{Val:2}
	n4 := &TreeNode{Val:5}

	n1.Left = n2
	n1.Right = n3
	n2.Left = n4

	t1 := &TreeNode{Val:2}
	t2 := &TreeNode{Val:1}
	t3 := &TreeNode{Val:3}
	t4 := &TreeNode{Val:4}
	t5 := &TreeNode{Val:7}

	t1.Left = t2
	t1.Right = t3
	t2.Right = t4
	t3.Right = t5


	fmt.Println(DumpBinaryTree(mergeTrees(n1, t1)))
}