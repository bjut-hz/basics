package findFirstAndLastPositionOfElementInSortedArray

/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

func searchRange(nums []int, target int) []int {
	if 0 == len(nums) { return []int{-1, -1} }

	left := 0
	right := len(nums) - 1

	for left <= right {
		mid := left + (right - left) / 2
		if target == nums[mid] {
			i, j := mid, mid
			for i - 1 >= 0 && nums[i - 1] == target {
				i--
			}

			for j + 1 < len(nums) && nums[j + 1] == target {
				j++
			}
			return []int{i, j}
		} else if target < nums[mid] {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}

	return []int{-1, -1}
}