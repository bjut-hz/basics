package houseRobberIII


/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root."
Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses
in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken
into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \
     3   1

Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
*/

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func rob(root *TreeNode) int {
	if root == nil {
		return 0
	}

	val := root.Val
	if nil != root.Left {
		val += rob(root.Left.Left) + rob(root.Left.Right)
	}

	if nil != root.Right {
		val += rob(root.Right.Left) + rob(root.Right.Right)
	}

	valLeft := rob(root.Left)
	valRight := rob(root.Right)

	if val > valLeft + valRight {
		return val
	} else {
		return valLeft + valRight
	}
}

// use DP to optimize
func rob1(root *TreeNode) int {
	mem := make(map[*TreeNode]int, 10)
	var solution func(*TreeNode) int
	solution = func(root *TreeNode) int {
		if root == nil {
			return 0
		}

		if val, ok := mem[root]; ok {
			return val
		}

		val := root.Val
		if nil != root.Left {
			val += solution(root.Left.Left) + solution(root.Left.Right)
		}

		if nil != root.Right {
			val += solution(root.Right.Left) + solution(root.Right.Right)
		}

		valLeft := solution(root.Left)
		valRight := solution(root.Right)

		maxVal := val
		if val < valLeft + valRight {
			maxVal = valLeft + valRight
		}
		mem[root] = maxVal
		return maxVal
	}

	return solution(root)
}

func rob2(root *TreeNode) int {
	var max2 func(int, int) int
	max2 = func(a, b int) int {
		if a > b {
			return a
		}
		return b
	}

	var solution func(*TreeNode) []int
	solution = func(root *TreeNode)[]int {
		if nil == root {
			return []int{0, 0}
		}

		left := solution(root.Left)
		right := solution(root.Right)
		ret := make([]int, 2)

		// rob root
		ret[0] = root.Val + left[1] + right[1]
		// does not rob root
		ret[1] = max2(left[0], left[1]) + max2(right[0], right[1])
		return ret
	}

	ret := solution(root)
	return max2(ret[0], ret[1])
}