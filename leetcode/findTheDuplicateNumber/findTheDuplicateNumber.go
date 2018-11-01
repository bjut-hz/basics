package findTheDuplicateNumber

/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one
duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

func findDuplicate(nums []int) int {
	N := len(nums)
	if N <= 1 {
		return -1
	}

	left, right := 1, N - 1
	for {
		mid := left + (right - left) / 2
		cnt := 0
		midCnt := 0
		for i := 0; i < N; i++ {
			if nums[i] < mid {
				cnt++
			} else if nums[i] == mid {
				midCnt++
			}
		}

		if midCnt > 1 {
			return mid
		}

		if cnt >= mid {
			right = mid -1
		} else {
			left = mid + 1
		}
	}
}

// linked list cycle: there must be an cycle, if we use nums[i] as the array index
func findDuplicate1(nums []int) int {
	if 0 == len(nums) {
		return -1
	}
	fast, slow := nums[0], nums[0]
	for {
		fast = nums[nums[fast]]
		slow = nums[slow]

		if fast == slow {
			break
		}
	}

	// find the cycle entry
	ptr := nums[0]
	for ptr != slow {
		ptr = nums[ptr]
		slow = nums[slow]
	}
	return ptr
}