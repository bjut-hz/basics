package firstMissingPositive

import "sort"

/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
*/

// sort and find
func firstMissingPositive(nums []int) int {
	sort.Ints(nums)

	ans := 1
	for i := 0; i < len(nums); i++ {
		if nums[i] <= 0 {
			continue
		} else {
			if nums[i] < ans {
				continue
			} else if nums[i] > ans {
				return ans
			} else {
				ans++
			}
		}
	}

	return ans
}

// set
func firstMissingPositive1(nums []int) int {
	set := make(map[int]bool, len(nums))
	for i := 0; i < len(nums); i++ {
		set[nums[i]] = true
	}

	ans := 1
	for {
		if _, ok := set[ans]; !ok {
			return ans
		} else {
			ans++
		}
	}
}

// put i at (i-1) position
func firstMissingPositive2(nums []int) int {
	n := len(nums)
	for i := 0; i < n; i++ {
		for nums[i] > 0 && nums[i] <=n && nums[nums[i]-1] != nums[i] {
			nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]
		}
	}

	for i := 0; i < n; i++ {
		if nums[i] != i + 1 {
			return i+1
		}
	}
	return n+1
}