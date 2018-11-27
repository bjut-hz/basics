package maximalRectangle

import "container/list"

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
*/

func largestRectangleArea(heights []int) int {
	area := 0
	stack := list.New()

	heights = append(heights, 0)
	for i := 0; i < len(heights); i++ {
		for 0 != stack.Len() && heights[stack.Front().Value.(int)] >= heights[i] {
			ele := stack.Front()
			stack.Remove(ele)

			cur := ele.Value.(int)
			height := heights[cur]
			var width int
			if 0 == stack.Len() {
				width = i
			} else {
				width = i - stack.Front().Value.(int) - 1 // those bigger than heights[cur] has already popped from stack, so we should top now to calculate width
			}

			if height * width > area {
				area = height * width
			}
		}

		stack.PushFront(i)
	}
	return area
}

func maximalRectangle(matrix [][]byte) int {
	if 0 == len(matrix) { return 0 }

	area := 0
	heights := make([]int, len(matrix[0]))
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[i]); j++ { // skill here
			if matrix[i][j] == '0' {
				heights[j] = 0
			} else {
				heights[j]++
			}
		}

		res := largestRectangleArea(heights)
		if res > area {
			area = res
		}
	}
	return area
}