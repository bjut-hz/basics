package subtreeOfAnotherTree


import (
	"testing"
	"fmt"
)

func TestMinStack(t *testing.T) {
	n1 := &TreeNode{Val:1}
	n2 := &TreeNode{Val:1}
	n3 := &TreeNode{Val:1}
	n4 := &TreeNode{Val:1}
	n5 := &TreeNode{Val:1}
	n6 := &TreeNode{Val:1}
	n7 := &TreeNode{Val:1}
	n8 := &TreeNode{Val:1}
	n9 := &TreeNode{Val:1}
	n10 := &TreeNode{Val:1}
	n11 := &TreeNode{Val:1}
	n12 := &TreeNode{Val:2}

	n1.Right = n2
	n2.Right = n3
	n3.Right = n4
	n4.Right = n5
	n5.Right = n6
	n6.Right = n7
	n7.Right = n8
	n8.Right = n9
	n9.Right = n10
	n10.Right = n11
	n11.Left = n12

	t1 := &TreeNode{Val:1}
	t2 := &TreeNode{Val:1}
	t3 := &TreeNode{Val:1}
	t4 := &TreeNode{Val:1}
	t5 := &TreeNode{Val:1}
	t6 := &TreeNode{Val:1}
	t7 := &TreeNode{Val:2}
	t1.Right = t2
	t2.Right = t3
	t3.Right = t4
	t4.Right = t5
	t5.Right = t6
	t6.Left = t7

	fmt.Println(isSame(n6, t1))
	fmt.Println(isSubtree(n1, t1))
}