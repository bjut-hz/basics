package largestRectangleInHistogram

import "container/list"

/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of
largest rectangle in the histogram.




Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].




The largest rectangle is shown in the shaded area, which has area = 10 unit.
*/


// brute force
func largestRectangleArea(heights []int) int {
	area := 0
	for i := 0; i < len(heights); i++ {
		height := heights[i]
		for j := i; j < len(heights); j++ {
			if heights[j] < height { height = heights[j] }

			if height * (j - i + 1) > area {
				area = height * (j - i + 1)
			}
		}
	}
	return area
}


// Pruning optimize
func largestRectangleArea1(heights []int) int {
	area := 0
	for i := 0; i < len(heights); i++ {
		if i < len(heights) - 1 && heights[i] < heights[i+1] { continue }

		height := heights[i]
		for j := i; j >= 0; j-- {
			if heights[j] < height { height = heights[j] }

			if height * (i - j + 1) > area {
				area = height * (i - j + 1)
			}
		}
	}

	return area
}

// using monotone stack
func largestRectangleArea2(heights []int) int {
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