package targetSum



/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -.
For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/



func solution(nums []int, target int, idx int, sum int, result *int) {
	if sum == target && idx == len(nums) {
		*result++
	}

	if idx >= len(nums) {
		return
	}

	solution(nums, target, idx+1, sum + nums[idx], result)
	solution(nums, target, idx+1, sum - nums[idx], result)
}

// use mem
func solution1(nums []int, target int, idx int, sum int, mem []map[int]int) int {
	if idx == len(nums) {
		if sum == target {
			return 1
		} else {
			return 0
		}
	}

	if _, ok := mem[idx][sum]; !ok {
		cnt1 := solution1(nums, target, idx+1, sum + nums[idx], mem)
		cnt2 := solution1(nums, target, idx+1, sum - nums[idx], mem)
		mem[idx][sum] = cnt1 + cnt2
	}
	return mem[idx][sum]
}


func findTargetSumWays(nums []int, S int) int {
	mem := make([]map[int]int, len(nums))
	for i := 0; i < len(nums); i++ {
		mem[i] = make(map[int]int, 1)
	}
	solution1(nums, S, 0, 0, mem)
	return solution1(nums, S, 0, 0, mem)
}

