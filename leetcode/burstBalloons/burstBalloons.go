package burstBalloons

/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums.
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
Example:

Input: [3,1,5,8]
Output: 167
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/


// DP[left][right] = max(DP[left][right], nums[left-1] * nums[i] * nums[right+1] + DP[left][i-1] + DP[i+1][right])
// (left <= i <= right), ith balloon as the last burst one.
func maxCoins(nums []int) int {
	N := len(nums)

	N = N + 2
	newNums := make([]int, N, N)
	newNums[0] = 1
	newNums[N - 1] = 1
	copy(newNums[1:N-1], nums)

	N = len(newNums)
	DP := make([][]int, N, N)
	for i := range DP {
		DP[i] = make([]int, N, N)
	}

	for i := 1; i < N -1; i++ {
		DP[i][i] = newNums[i-1] * newNums[i] * newNums[i+1]
	}

	// solve the sub problem first
	for left := N - 1; left > 0 ; left-- {
		for right := left+1; right < N-1; right++ {
			for i := left; i <= right; i++ {
				if newNums[left - 1] * newNums[i] * newNums[right+1] + DP[left][i-1] + DP[i+1][right] > DP[left][right] {
					DP[left][right] = newNums[left - 1] * newNums[i] * newNums[right+1] + DP[left][i-1] + DP[i+1][right]
				}
			}
		}
	}
	return DP[1][N-2]
}