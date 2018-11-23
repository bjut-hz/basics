package binaryTree

// https://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html

/*
1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。

2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。

   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。输出当前节点（在这里输出，这是与中序遍历唯一一点不同）。当前节点更新为当前节点的左孩子。

   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空。当前节点更新为当前节点的右孩子。

3. 重复以上1、2直到当前节点为空。
*/
func morrisPreOrder(root *TreeNode) []int {
	result := make([]int, 0)

	cur := root
	var pre *TreeNode
	for cur != nil {
		if cur.Left == nil {
			result = append(result, cur.Val)
			cur = cur.Right
		} else {
			pre = cur.Left
			for pre.Right != nil && pre.Right != cur {
				pre = pre.Right
			}

			if pre.Right == nil {
				result = append(result, cur.Val)

				pre.Right = cur
				cur = cur.Left
			} else {
				pre.Right = nil
				cur = cur.Right
			}
		}
	}

	return result
}


/*
1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。

2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。

   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。

   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。

3. 重复以上1、2直到当前节点为空。
*/
func morrisInOrder(root *TreeNode) []int {
	result := make([]int, 0)

	cur := root
	var pre *TreeNode
	for cur != nil {
		if cur.Left == nil {
			result = append(result, cur.Val)
			cur = cur.Right
		} else {
			pre = cur.Left
			for pre.Right != nil && pre.Right != cur {
				pre = pre.Right
			}

			if pre.Right == nil {
				pre.Right = cur
				cur = cur.Left
			} else {
				pre.Right = nil
				result = append(result, cur.Val)
				cur = cur.Right
			}
		}
	}

	return result
}

/*
后续遍历稍显复杂，需要建立一个临时节点dump，令其左孩子是root。并且还需要一个子过程，就是倒序输出某两个节点之间路径上的各个节点。

当前节点设置为临时节点dump。

1. 如果当前节点的左孩子为空，则将其右孩子作为当前节点。

2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。

   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。

   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空。倒序输出从当前节点的左孩子到该前驱节点这条路径上的所有节点。当前节点更新为当前节点的右孩子。

3. 重复以上1、2直到当前节点为空。
*/
func morrisPostOrder(root *TreeNode) []int {
	reverse := func(from, to *TreeNode) {
		if from == to { return }

		x := from
		y := from.Right
		var z *TreeNode

		for {
			z = y.Right
			y.Right = x
			x = y
			y = z
			if x == to { break }
		}
	}

	getResult := func(from, to *TreeNode) []int {
		ret := make([]int, 0)
		reverse(from, to)
		p := to
		for {
			ret = append(ret, p.Val)
			if p == from { break }
			p = p.Right
		}
		reverse(from, to)
		return ret
	}

	result := make([]int , 0)
	dump := TreeNode{}
	dump.Left = root
	cur := &dump
	var prev *TreeNode

	for cur != nil {
		if cur.Left == nil {
			cur = cur.Right
		} else {
			prev = cur.Left

			for prev.Right != nil && prev.Right != cur {
				prev = prev.Right
			}

			if prev.Right == nil {
				prev.Right = cur
				cur = cur.Left
			} else {
				result = append(result, getResult(cur.Left, prev)...)
				prev.Right = nil
				cur = cur.Right
			}
		}
	}

	return result
}