package productOfArrayExceptSelf

/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of
all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of
space complexity analysis.)
*/


func productExceptSelf(nums []int) []int {
	N := len(nums)

	if 0 == N || 1 == N {
		return nums
	}

	frontProduct := make([]int, N, N)
	tailProduct := make([]int, N, N)

	frontProduct[0] = nums[0]
	tailProduct[N-1] = nums[N-1]
	for i, j := 1, N - 2; i < N; i,j = i+1,j-1 {
		frontProduct[i] = frontProduct[i-1] * nums[i]
		tailProduct[j] = tailProduct[j+1] * nums[j]
	}

	result := make([]int, N, N)
	result[0] = tailProduct[1]
	result[N-1] = frontProduct[N-2]

	for i := 1; i < N -1; i++ {
		result[i] = frontProduct[i-1] * tailProduct[i+1]
	}
	return result
}