package trappingRainWater

import "container/list"

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it
is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water
(blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

// brute force
func trap(height []int) int {
	result := 0
	for i := 1; i < len(height) - 1; i++ {
		maxLeft := 0
		maxRight := 0
		for j := i; j >= 0; j-- {
			if height[j] > maxLeft {
				maxLeft = height[j]
			}
		}

		for k := i; k < len(height); k++ {
			if height[k] > maxRight {
				maxRight = height[k]
			}
		}

		h := maxLeft
		if maxRight < maxLeft { h = maxRight }

		result += h - height[i]
	}

	return result
}


func max2(a, b int) int {
	if a > b { return a }
	return b
}

func min2(a, b int) int {
	if a < b { return a }
	return b
}


// DP:
// left_max[i], right_max[i]
func trap1(height []int) int {


	N := len(height)
	if N < 1 { return 0 }

	result := 0
	leftMax := make([]int, len(height))
	rightMax := make([]int, len(height))

	leftMax[0] = height[0]
	rightMax[N - 1] = height[N - 1]

	for i := 1; i < N - 1; i++ {
		leftMax[i] = max2(height[i], leftMax[i-1])
	}

	for j := N - 2; j >= 0; j-- {
		rightMax[j] = max2(height[j], rightMax[j+1])
	}

	for i := 1; i < N - 1; i++ {
		result += min2(leftMax[i], rightMax[i]) - height[i]
	}

	return result
}

// two pointer
func trap2(height []int) int {
	l := 0
	r := len(height) - 1
	res := 0
	for l < r {
		mn := min2(height[l], height[r])
		if mn == height[l] {
			// forward l
			l++
			for l < r && height[l] < mn {
				res += mn - height[l]
				l++
			}
		} else {
			// forward r
			r--
			for l < r && height[r] < mn {
				res += mn - height[r]
				r--
			}
		}
	}

	return res
}


// stack
func trap3(height []int) int {
	result := 0
	stack := list.New()
	for i := 0; i < len(height); {
		if 0 == stack.Len() || height[stack.Front().Value.(int)] >= height[i] {
			stack.PushFront(i)
			i++
		} else {
			ele := stack.Front()
			stack.Remove(ele)
			if 0 == stack.Len() { continue }

			top := stack.Front()
			result += (min2(height[top.Value.(int)], height[i]) - height[ele.Value.(int)]) * (i - top.Value.(int) - 1)
		}
	}

	return result
}