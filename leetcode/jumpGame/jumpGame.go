package jumpGame

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
*/

func max2(a, b int) int {
	if a > b { return a }
	return b
}

// DP[i]表示达到i时还能跳跃的步数
// DP[i] = max(DP[i-1], nums[i-1]) - 1
func canJump(nums []int) bool {
	DP := make([]int, len(nums))

	for i := 1; i < len(nums); i++ {
		DP[i] = max2(DP[i-1], nums[i-1]) - 1
		if DP[i] < 0 { return false }
	}

	return DP[len(nums) - 1] >= 0
}

// greedy
func canJump1(nums []int) bool {
	reach := 0
	for i := 0; i < len(nums); i++ {
		if i > reach || reach >= len(nums) - 1 { break }
		reach = max2(i + nums[i], reach)
	}

	return reach >= len(nums) - 1
}