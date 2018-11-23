package binaryTree

func preOrderTraverse(root *TreeNode) []int {
	if nil == root { return []int{} }

	result := make([]int, 0)
	result = append(result, root.Val)
	result = append(result, preOrderTraverse(root.Left)...)
	result = append(result, preOrderTraverse(root.Right)...)

	return result
}

func inOrderTraverse(root *TreeNode) []int {
	if nil == root { return []int{} }

	result := make([]int, 0)
	result = append(result, inOrderTraverse(root.Left)...)
	result = append(result, root.Val)
	result = append(result, inOrderTraverse(root.Right)...)

	return result
}

func postOrderTraverse(root *TreeNode) []int {
	if nil == root { return []int{} }

	result := make([]int, 0)
	result = append(result, postOrderTraverse(root.Left)...)
	result = append(result, postOrderTraverse(root.Right)...)
	result = append(result, root.Val)

	return result
}