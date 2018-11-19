package maximumSubarray

import "math"

/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

func maxSubArray(nums []int) int {
	if 0 == len(nums) { return 0}

	result := nums[0]

	sumNow := nums[0] // max sum until nums[i]
	N := len(nums)
	for i := 1; i < N; i++ {
		if sumNow + nums[i] > nums[i] {
			sumNow = sumNow + nums[i]
		} else {
			sumNow = nums[i]
		}

		if sumNow > result {
			result = sumNow
		}
	}

	return result
}