package _Sum

import (
	"sort"
)

/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

// sort nums and fix one then find remaining two num
func threeSum(nums []int) [][]int {
	result := make([][]int, 0, 10)
	sort.Ints(nums)

	if 0 == len(nums) || nums[0] > 0 || nums[len(nums) - 1] < 0 {
		return [][]int{}
	}

	for i := 0; i < len(nums); i++ {
		if nums[i] > 0 { // prune
			break
		}

		if i - 1 >= 0 && nums[i] == nums[i-1] { // remove duplicate
			continue
		}

		target := -nums[i]
		left := i + 1
		right := len(nums) - 1

		for left < right {
			sum := nums[left] + nums[right]
			if sum == target {
				result = append(result, []int{nums[i], nums[left], nums[right]})

				right--
				for right > left && nums[right] == nums[right + 1] {
					right--
				}

				left++
				for right > left && nums[left] == nums[left - 1] {
					left++
				}
			} else if sum > target {
				right--
			} else {
				left++
			}
		}
	}

	return result
}