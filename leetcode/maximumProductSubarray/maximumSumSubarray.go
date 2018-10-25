package maximumProductSubarray

import (
	"math"
)

func maxSum1(nums []int) int {
	result := math.MinInt64

	N := len(nums)
	for i := 0; i < N; i++ {
		for j := i; j < N; j++ {
			tmp := 0
			for k := i; k <= j; k++ {
				tmp += nums[k]
			}
			if tmp > result {
				result = tmp
			}
		}
	}

	return result
}

func maxSum2(nums []int) int {
	result := math.MinInt64

	N := len(nums)
	for i := 0; i < N; i++ {
		tmp := 0
		for j := i; j < N; j++ {
			tmp += nums[j]
			if tmp > result {
				result = tmp
			}
		}
	}

	return result
}

func max3(a, b, c int) int {
	if a >= b && a >= c {
		return a
	}
	if b >= a && b >= c {
		return b
	}
	if c >= a && c >= b {
		return c
	}
	return a
}
// use divide and conquer
func maxSum3(nums []int) int {
	N := len(nums)
	if 1 == N {
		if nums[0] > 0 {
			return nums[0]
		} else {
			return 0
		}
	}

	center := N / 2
	leftPart := nums[0:center]
	rightPart := nums[center:]
	leftMax := maxSum3(leftPart)
	rightMax := maxSum3(rightPart)

	leftBorderMax := 0
	leftBorderSum := 0
	for i := center - 1; i >= 0; i--{
		leftBorderSum += nums[i]
		if leftBorderSum > leftBorderMax {
			leftBorderMax = leftBorderSum
		}
	}

	rightBorderMax := 0
	rightBorderSum := 0
	for i := center; i < N; i++ {
		rightBorderSum += nums[i]
		if rightBorderSum > rightBorderMax {
			rightBorderMax = rightBorderSum
		}
	}

	return max3(leftMax, rightMax, leftBorderMax + rightBorderMax)
}

// use DP A[i] = max(A[i-1] + nums[i], nums[i])
func maxSum4(nums []int) int {
	 result := math.MinInt64

	 sumNow := math.MinInt64 // max sum until nums[i]
	 N := len(nums)
	 for i := 0; i < N; i++ {
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
