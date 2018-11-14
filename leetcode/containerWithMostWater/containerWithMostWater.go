package containerWithMostWater

/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.





The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.



Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

func maxArea(height []int) int {
	N := len(height)

	area := 0
	for i := 0; i < N; i++ {
		for j := i + 1; j < N; j++ {
			areaLen := height[j]
			if height[j] > height[i] {
				areaLen = height[i]
			}

			if areaLen * (j-i) > area {
				area = areaLen * (j-i)
			}
		}
	}
	return area
}

func maxArea1(height []int) int {
	min2 := func(a, b int) int {
		if a < b {return a}
		return b
	}

	max2 := func(a, b int) int {
		if a > b {return a}
		return b
	}

	N := len(height)
	area := 0

	left := 0
	right := N - 1

	for left < right {
		area = max2(area, min2(height[left], height[right]) * (right - left))
		if height[left] < height[right] {
			left++
		} else {
			right--
		}
	}

	return area
}