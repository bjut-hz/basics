package maximumProductSubarray

import "math"

/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

func min3(a, b, c int) int {
	if a <= b && a <= c {
		return a
	}

	if b <= a && b <= c {
		return b
	}

	if c <= a && c <= b {
		return c
	}
	return a
}

// use DP
func maxProduct(nums []int) int {
	result := math.MinInt64

	maxEndingHere := 1
	minEndingHere := 1
	N := len(nums)
	for i := 0; i < N; i++ {
		// there is negative number, so we should record the min
		newMaxEndingHere := max3(maxEndingHere * nums[i], minEndingHere * nums[i], nums[i])
		newMinEndingHere := min3(maxEndingHere * nums[i], minEndingHere * nums[i], nums[i])

		if newMaxEndingHere > result {
			result = newMaxEndingHere
		}

		if newMinEndingHere > result {
			result = newMinEndingHere
		}

		maxEndingHere = newMaxEndingHere
		minEndingHere = newMinEndingHere
	}

	return result
}