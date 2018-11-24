package singleNumber

/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/

// use map
func singleNumber(nums []int) int {
	dic := make(map[int]bool, len(nums))
	for i := 0; i < len(nums); i++ {
		if _, ok := dic[nums[i]]; ok {
			delete(dic, nums[i])
		} else {
			dic[nums[i]] = true
		}
	}

	for k := range dic {
		return k
	}
	return 0
}

// use xor
func singleNumber1(nums []int) int {
	result := nums[0]
	for i := 1; i < len(nums); i++ {
		result ^= nums[i]
	}
	return result
}