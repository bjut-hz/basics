package binaryTree

import "container/list"

/*
	1、将根结点入栈；
	2、每次从栈顶弹出一个结点，访问该结点；
	3、把当前结点的右孩子入栈；
	4、把当前结点的左孩子入栈。
*/
func preOrder(root *TreeNode) []int {
	result := make([]int, 0)

	stack := list.New()
	if nil != root {
		stack.PushFront(root)
	}

	for 0 != stack.Len() {
		ele := stack.Front()
		stack.Remove(ele)

		ptr := ele.Value.(*TreeNode)

		result = append(result, ptr.Val)

		if nil != ptr.Right {
			stack.PushFront(ptr.Right)
		}

		if nil != ptr.Left {
			stack.PushFront(ptr.Left)
		}
	}

	return result
}


/*
	1、初始化一个二叉树结点pNode指向根结点；
	2、若pNode非空，那么就把pNode入栈，并把pNode变为其左孩子；（直到最左边的结点）
	3、若pNode为空，弹出栈顶的结点，并访问该结点，将pNode指向其右孩子（访问最左边的结点，并遍历其右子树）
*/
func inOrder(root *TreeNode) []int {
	result := make([]int, 0)
	stack := list.New()

	ptr := root
	for nil != ptr || 0 != stack.Len() {
		if nil == ptr {
			ele := stack.Front()
			stack.Remove(ele)

			pos := ele.Value.(*TreeNode)
			result = append(result, pos.Val)
			ptr = pos.Right
		} else {
			stack.PushFront(ptr)
			ptr = ptr.Left
		}
	}

	return result
}

/*
	1、设置两个栈stk, stk2；
	2、将根结点压入第一个栈stk；
	3、弹出stk栈顶的结点，并把该结点压入第二个栈stk2；
	4、将当前结点的左孩子和右孩子先后分别入栈stk；
	5、当所有元素都压入stk2后，依次弹出stk2的栈顶结点，并访问之。
*/
func postOrder(root *TreeNode) []int {
	result := make([]int, 0)
	stk1, stk2 := list.New(), list.New()

	if nil != root {
		stk1.PushFront(root)
	}

	for 0 != stk1.Len() {
		ele := stk1.Front()
		stk1.Remove(ele)

		ptr := ele.Value.(*TreeNode)
		stk2.PushFront(ptr)

		if nil != ptr.Left {
			stk1.PushFront(ptr.Left)
		}

		if nil != ptr.Right {
			stk1.PushFront(ptr.Right)
		}
	}

	for 0 != stk2.Len() {
		ele := stk2.Front()
		result = append(result, ele.Value.(*TreeNode).Val)
		stk2.Remove(ele)
	}

	return result
}