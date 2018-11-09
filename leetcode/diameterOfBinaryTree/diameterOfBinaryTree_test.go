package diameterOfBinaryTree

import (
	"testing"
	"fmt"
)

func TestHeight(t *testing.T)  {
	//[4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2]

	n1 := &TreeNode{Val:4}
	n2 := &TreeNode{Val:-7}
	n3 := &TreeNode{Val:-3}
	n4 := &TreeNode{Val:-9}
	n5 := &TreeNode{Val:-3}
	n6 := &TreeNode{Val:9}
	n7 := &TreeNode{Val:-7}
	n8 := &TreeNode{Val:-4}
	n9 := &TreeNode{Val:6}
	n10 := &TreeNode{Val:-6}
	n11 := &TreeNode{Val:-6}
	n12 := &TreeNode{Val:0}
	n13 := &TreeNode{Val:6}
	n14 := &TreeNode{Val:5}
	n15 := &TreeNode{Val:9}
	n16:= &TreeNode{Val:-1}
	n17:= &TreeNode{Val:-4}
	n18 := &TreeNode{Val:-2}

	n1.Left = n2
	n1.Right = n3
	n3.Left = n4
	n3.Right = n5

	n4.Left = n6
	n4.Right = n7
	n5.Left = n8

	n6.Left = n9
	n7.Left = n10
	n7.Right = n11
	n9.Left = n12
	n9.Right = n13
	n10.Left = n14
	n11.Left = n15
	n13.Right = n16
	n14.Left = n17

	n16.Left = n18

	fmt.Println(height(n2))
	fmt.Println(height(n3))

}

func TestDiameterOfBinaryTree(t *testing.T) {
	n1 := &TreeNode{Val:4}
	n2 := &TreeNode{Val:-7}
	n3 := &TreeNode{Val:-3}
	n4 := &TreeNode{Val:-9}
	n5 := &TreeNode{Val:-3}
	n6 := &TreeNode{Val:9}
	n7 := &TreeNode{Val:-7}
	n8 := &TreeNode{Val:-4}
	n9 := &TreeNode{Val:6}
	n10 := &TreeNode{Val:-6}
	n11 := &TreeNode{Val:-6}
	n12 := &TreeNode{Val:0}
	n13 := &TreeNode{Val:6}
	n14 := &TreeNode{Val:5}
	n15 := &TreeNode{Val:9}
	n16:= &TreeNode{Val:-1}
	n17:= &TreeNode{Val:-4}
	n18 := &TreeNode{Val:-2}

	n1.Left = n2
	n1.Right = n3
	n3.Left = n4
	n3.Right = n5

	n4.Left = n6
	n4.Right = n7
	n5.Left = n8

	n6.Left = n9
	n7.Left = n10
	n7.Right = n11
	n9.Left = n12
	n9.Right = n13
	n10.Left = n14
	n11.Left = n15
	n13.Right = n16
	n14.Left = n17

	n16.Left = n18

	fmt.Println(height(n2))
	fmt.Println(height(n3))

	fmt.Println(diameterOfBinaryTree(n1))

}
