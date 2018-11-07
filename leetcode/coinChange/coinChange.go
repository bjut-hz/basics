package coinChange


/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the
fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination
of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/

// DP[i] = min(DP[i], DP[i-nums[j]]+1)
func coinChange(coins []int, amount int) int {
	DP := make([]int, amount + 1)
	for i := range DP {
		DP[i] = -1 // flag
	}

	DP[0] = 0
	for _, v := range coins {
		if v <= amount {
			DP[v] = 1
		}
	}

	for i := 1; i <= amount; i++ {
		for _, v := range coins {
			if i - v > 0 {
				if -1 != DP[i-v] {
					if DP[i] == -1 {
						DP[i] = DP[i - v] + 1
					} else if DP[i - v] + 1 < DP[i] {
						DP[i] = DP[i - v] + 1
					}
				}
			}
		}
	}
	return DP[amount]
}