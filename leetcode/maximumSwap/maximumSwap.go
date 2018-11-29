package maximumSwap

/*
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]
*/

func maxSwap(nums []int) {
	if 0 == len(nums) { return }
	max := nums[0]
	idx := 0
	for i := 1; i < len(nums); i++ {
		if nums[i] > max {
			max = nums[i]
			idx = i
		}
	}
	if idx == len(nums) - 1 || nums[idx] == nums[len(nums) - 1] {
		maxSwap(nums[0:len(nums)-1])
	} else {
		nums[len(nums)-1], nums[idx] = nums[idx], nums[len(nums)-1]
	}
}

func maximumSwap(num int) int {
	if 0 == num { return 0 }
	nums := make([]int, 0, 32)

	for num != 0 {
		nums = append(nums, num % 10)
		num /= 10
	}

	maxSwap(nums)

	for i := len(nums) - 1; i >= 0; i-- {
		num = num * 10 + nums[i]
	}

	return num
}