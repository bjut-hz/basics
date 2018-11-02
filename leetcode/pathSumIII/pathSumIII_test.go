package pathSumIII


import (
	"testing"
	"fmt"
)

func TestPathSum(t *testing.T) {
	n1 := &TreeNode{Val:10}
	n2 := &TreeNode{Val:5}
	n3 := &TreeNode{Val:-3}
	n4 := &TreeNode{Val:3}
	n5 := &TreeNode{Val:2}
	n6 := &TreeNode{Val:11}
	n7 := &TreeNode{Val:3}
	n8 := &TreeNode{Val:-2}
	n9 := &TreeNode{Val:1}

	n1.Left = n2
	n1.Right = n3
	n2.Left = n4
	n2.Right = n5
	n3.Right = n6
	n4.Left = n7
	n4.Right = n8
	n5.Right = n9



	fmt.Println(pathSum(n1, 8))
}