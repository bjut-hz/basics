package houseRobberIII


import (
	"testing"
	"fmt"
)

func TestRobIII(t *testing.T) {
	n1 := &TreeNode{Val:3}
	n2 := &TreeNode{Val:2}
	n3 := &TreeNode{Val:3}
	n4 := &TreeNode{Val:3}
	n5 := &TreeNode{Val:1}

	n1.Left = n2
	n1.Right = n3
	n2.Right = n4
	n3.Right = n5
	fmt.Println(rob(n1))
	fmt.Println(rob1(n1))
	fmt.Println(rob2(n1))
}