package subarraySumEqualsK

/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

func subarraySum(nums []int, k int) int {
	N := len(nums)
	result := 0
	for i := 0; i < N; i++ {
		sum := 0
		for j := i; j < N; j++ {
			sum += nums[j]
			if sum == k {
				result++
			}
		}
	}
	return result
}

func subarraySum1(nums []int, k int) int {
	N := len(nums)
	hashMap := make(map[int]int, N)
	hashMap[0] = 1

	sum := 0
	result := 0
	for i := 0; i < N; i++ {
		sum += nums[i]
		result += hashMap[sum-k]
		hashMap[sum]++
	}
	return result
}