package binaryTreeMaximumPathSum


import (
	"testing"
	"fmt"
)



func TestMaxRootPathSum(t *testing.T) {
	n1 := &TreeNode{Val:-2}
	n2 := &TreeNode{Val:-1}
	//n3 := &TreeNode{Val:20}
	//n4 := &TreeNode{Val:15}
	//n5 := &TreeNode{Val:7}
	//
	//
	n1.Left = n2
	//n1.Right = n3
	//n3.Left = n4
	//n3.Right = n5

	//fmt.Println(maxRootPathSum(n1))
	//fmt.Println(maxRootPathSum(n2))
	//fmt.Println(maxRootPathSum(n3))
	//fmt.Println(maxRootPathSum(n4))
	fmt.Println(maxPathSum(n1))
	fmt.Println(maxPathSum1(n1))

}