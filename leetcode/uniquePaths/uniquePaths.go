package uniquePaths

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
*/

func uniquePaths(m int, n int) int {
	if 0 == m || 0 == n { return 0 }

	DP := make([][]int, m)
	for i := 0; i < m ; i++ {
		DP[i] = make([]int, n)
		DP[i][0] = 1
	}

	for j := 0; j < n; j++ {
		DP[0][j] = 1
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			DP[i][j] = DP[i][j-1] + DP[i-1][j]
		}
	}
	return DP[m-1][n-1]
}