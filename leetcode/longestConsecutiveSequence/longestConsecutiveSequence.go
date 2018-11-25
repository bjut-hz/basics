package longestConsecutiveSequence

import "sort"

/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

// use sort
func longestConsecutive(nums []int) int {
	if 0 == len(nums) { return 0}

	sort.Ints(nums)
	res := 1
	count := 1
	for i := 0; i < len(nums) - 1; i++ {
		if nums[i] == nums[i+1] {
			continue
		}

		if nums[i+1] - nums[i] == 1 {
			count++
			if count > res {
				res = count
			}
		} else {
			count = 1
		}
	}

	return res
}

// use Set
func longestConsecutive1(nums []int) int {
	hashMap := make(map[int]bool, len(nums))
	for _, num := range nums {
		hashMap[num] = true
	}

	longestStreak := 0
	for key := range hashMap {
		if !hashMap[key-1] { // use key-1 make sure we can attempt to build sequences from numbers that are not already part of a longer sequence
			current := key
			currentStreak := 1
			for hashMap[current+1] {
				current++
				currentStreak++
			}
			if currentStreak > longestStreak {
				longestStreak = currentStreak
			}
		}
	}

	return longestStreak
}